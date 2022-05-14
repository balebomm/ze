cmake_minimum_required(VERSION 3.22)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Default build type is Release.")
endif()

set(ZE_DEBUG_MODE OFF)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(ZE_DEBUG_MODE ON)
endif()

option(ZE_PEDANTIC "Enable extra warning using standard language flags" OFF)
option(ZE_WERROR   "Halt compiler warnings into errors"                 OFF)
option(ZE_INSTALL  "Generate install target"                            ${ZE_DEBUG_MODE})
option(ZE_TEST     "Generate test target module when debug"             ${ZE_DEBUG_MODE})
option(ZE_EXAMPLE  "Generate example module when debug"                 ${ZE_DEBUG_MODE})
option(ZE_DOC      "Generate doc module"                                OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "vcpkg toolchain file")

project(ZE CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CheckCXXCompilerFlag)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(ZE_PEDANTIC_FLAGS -pedantic -Wall -pedantic-errors -Werror
        -Wredundant-decls -Wwrite-strings -Wpointer-arith
        -Wcast-qual -Wformat=2 -Wmissing-include-dirs -Wcast-align
        -Wctor-dtor-privacy -Wdisabled-optimization
        -Winvalid-pch -Woverloaded-virtual
        -Wconversion -Wundef
        -Wno-ctor-dtor-privacy -Wno-format-nonliteral)
    if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.6)
        set(ZE_PEDANTIC_FLAGS ${ZE_PEDANTIC_FLAGS}
            -Wno-dangling-else -Wno-unused-local-typedefs)
    endif()
    if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5.0)
        set(ZE_PEDANTIC_FLAGS ${ZE_PEDANTIC_FLAGS} -Wdouble-promotion
            -Wtrampolines -Wzero-as-null-pointer-constant -Wuseless-cast
            -Wvector-operation-performance -Wsized-deallocation -Wshadow)
    endif()
    if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 6.0)
        set(ZE_PEDANTIC_FLAGS ${ZE_PEDANTIC_FLAGS} -Wshift-overflow=2
            -Wnull-dereference -Wduplicated-cond)
        check_cxx_compiler_flag(-Wzero-as-null-pointer-constant HAS_NULLPTR_WARNING)
        if (HAS_NULLPTR_WARNING)
            set(ZE_PEDANTIC_FLAGS ${ZE_PEDANTIC_FLAGS}
                -Wzero-as-null-pointer-constant)
        endif()
    endif()
    set(ZE_WERROR_FLAGS -Werror)
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(ZE_PEDANTIC_FLAGS -Wall -Wextra -pedantic -Wconversion -Wundef
        -Wdeprecated -Wweak-vtables -Wshadow
        -Wno-gnu-zero-variadic-macro-arguments)
    set(ZE_WERROR_FLAGS -Werror)
endif()

if (MSVC)
    set(ZE_PEDANTIC_FLAGS /W3)
    set(ZE_WERROR_FLAGS /WX)
endif()

include(GNUInstallDirs)
set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

#
include(ProvideDependencies)

find_program(PROTOBUF_PROTOC protoc)
find_program(GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)

# proto validate
make_directory(${CMAKE_CURRENT_BINARY_DIR}/proto/validate)
set(cxx_validate_proto "${CMAKE_CURRENT_BINARY_DIR}/proto/validate/validate.pb.cc")
add_custom_command(
    OUTPUT ${cxx_validate_proto}
    COMMAND ${PROTOBUF_PROTOC}
    ARGS --cpp_out=${CMAKE_CURRENT_BINARY_DIR}/proto/validate
        -I=${CMAKE_CURRENT_SOURCE_DIR}/model/validate
        --validate_out=lang=cc:${CMAKE_CURRENT_BINARY_DIR}/proto
        ${CMAKE_CURRENT_SOURCE_DIR}/model/validate/validate.proto
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/model/validate/validate.proto
)

add_library(proto-validate ${cxx_validate_proto})
target_include_directories(proto-validate PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/proto>" "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/proto")
target_include_directories(proto-validate PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/model>")

target_link_libraries(proto-validate PUBLIC LibGrpcGpr)
target_link_libraries(proto-validate PUBLIC LibGrpcUpb)
target_link_libraries(proto-validate PUBLIC LibGrpcGrpc)
target_link_libraries(proto-validate PUBLIC LibGrpcGrpcpp)
target_link_libraries(proto-validate PUBLIC LibGrpcReflection)

# proto files
file(GLOB PROTO_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} model/*.proto)

make_directory(${CMAKE_CURRENT_BINARY_DIR}/proto)
make_directory(${CMAKE_CURRENT_SOURCE_DIR}/web/proto)
foreach(proto_src ${PROTO_SRCS})
    string(REGEX MATCH "model/(.+).proto" match_var ${proto_src})
    set(cxx_proto_srcs     "${CMAKE_CURRENT_BINARY_DIR}/proto/${CMAKE_MATCH_1}.pb.cc")
    set(cxx_grpc_srcs      "${CMAKE_CURRENT_BINARY_DIR}/proto/${CMAKE_MATCH_1}.grpc.pb.cc")
    set(cxx_validate_srcs  "${CMAKE_CURRENT_BINARY_DIR}/proto/${CMAKE_MATCH_1}.pb.validate.cc")

    add_custom_command(
        OUTPUT ${cxx_proto_srcs} ${cxx_grpc_srcs} ${cxx_validate_srcs}
        COMMAND ${PROTOBUF_PROTOC}
        ARGS --grpc_out=${CMAKE_CURRENT_BINARY_DIR}/proto
            --cpp_out=${CMAKE_CURRENT_BINARY_DIR}/proto 
            --grpc-web_out=import_style=commonjs,mode=grpcweb:${CMAKE_CURRENT_SOURCE_DIR}/web/proto
            --js_out=import_style=commonjs,binary:${CMAKE_CURRENT_SOURCE_DIR}/web/proto
            -I=${CMAKE_CURRENT_SOURCE_DIR}/model
            --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN_EXECUTABLE}
            --validate_out=lang=cc:${CMAKE_CURRENT_BINARY_DIR}/proto
            ${CMAKE_CURRENT_SOURCE_DIR}/${proto_src}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${proto_src}
    )

    add_library(proto-${CMAKE_MATCH_1} ${cxx_proto_srcs} ${cxx_grpc_srcs} ${cxx_validate_srcs})
    target_link_libraries(proto-${CMAKE_MATCH_1} PUBLIC proto-validate)

    if (ZE_INSTALL)
        install(TARGETS proto-${CMAKE_MATCH_1}
                PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
                LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
                ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
                RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
    endif()
endforeach()

# cxx_services
set(CXX_SERVICES "auth;graph")

foreach(cxx_service_name ${CXX_SERVICES})
    file(GLOB cxx_service_source RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/${cxx_service_name}/*.cpp src/${cxx_service_name}/*/*.cpp)
    list(SORT cxx_service_source)
    add_library(${cxx_service_name} ${cxx_service_source})
    target_include_directories(${cxx_service_name} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/${cxx_service_name}>" "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
    target_include_directories(${cxx_service_name} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>")
    target_link_libraries(${cxx_service_name} PUBLIC proto-auth)
    target_link_libraries(${cxx_service_name} PUBLIC proto-graph)

    target_link_libraries(${cxx_service_name} PUBLIC LibZmq)

    if (ZE_PEDANTIC)
        target_compile_options(${cxx_service_name} PUBLIC ${ZE_PEDANTIC_FLAGS})
    endif()
    if (ZE_WERROR)
        target_compile_options(${cxx_service_name} PUBLIC ${ZE_WERROR_FLAGS})
    endif()
    if (BUILD_SHARED_LIBS)
        target_compile_definitions(${cxx_service_name} PRIVATE ZE_EXPORT INTERFACE ZE_SHARED)
    endif()
    
    set(cxx_service_bin "${cxx_service_name}_d")
    add_executable(${cxx_service_bin} ${CMAKE_CURRENT_SOURCE_DIR}/src/${cxx_service_name}/main.cpp)
    target_link_libraries(${cxx_service_bin} PRIVATE ${cxx_service_name}) 
endforeach()
# end cxx_services

include(ImportConfig)
configure_file(src/config.h.in config.h)

if (ZE_INSTALL)

    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/proto DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} PATTERN "*.cc" EXCLUDE)
    install(TARGETS proto-validate
            PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

    foreach(cxx_service_name ${CXX_SERVICES})
        install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/${cxx_service_name} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} PATTERN "*.cpp" EXCLUDE)
        install(TARGETS "${cxx_service_name}_d" DESTINATION ${CMAKE_INSTALL_BIN_DIR})
        install(TARGETS ${cxx_service_name}
                PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
                LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
                ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
                RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
    endforeach()
endif()

if (ZE_TEST)
    message(STATUS "Generating test module")
    enable_testing()
    add_subdirectory(test)
endif()

if (ZE_EXAMPLE)
    message(STATUS "Generating example module")
    add_subdirectory(example)
endif()

if (ZE_DOC)
    message(STATUS "Generating doc module")
    add_subdirectory(doc)
endif()
