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

# cxx_proto
file(GLOB CXX_PROTO_SOURCE RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/cpp/proto/proto/*.cc)
list(SORT CXX_PROTO_SOURCE)

add_library(cxx_proto ${CXX_PROTO_SOURCE})

target_link_libraries(cxx_proto PUBLIC LibGrpcGpr)
target_link_libraries(cxx_proto PUBLIC LibGrpcUpb)
target_link_libraries(cxx_proto PUBLIC LibGrpcGrpc)
target_link_libraries(cxx_proto PUBLIC LibGrpcGrpcpp)
target_link_libraries(cxx_proto PUBLIC LibGrpcReflection)
# end cxx_proto

# cxx_services
set(CXX_SERVICES "s_auth;s_graph")

foreach(cxx_service_name ${CXX_SERVICES})
    file(GLOB cxx_service_source RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/cpp/${cxx_service_name}/*/*.cpp src/cpp/${cxx_service_name}/*/*/*.cpp)
    list(SORT cxx_service_source)
    add_library(${cxx_service_name} ${cxx_service_source})
    target_include_directories(${cxx_service_name} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/${cxx_service_name}>" "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
    target_include_directories(${cxx_service_name} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/proto>" "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDE_DIR}>")
    target_include_directories(${cxx_service_name} PUBLIC "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>")
    target_link_libraries(${cxx_service_name} PUBLIC cxx_proto)
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
    add_executable(${cxx_service_bin} ${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/${cxx_service_name}/main.cpp)
    target_link_libraries(${cxx_service_bin} PRIVATE ${cxx_service_name}) 
endforeach()
# end cxx_services

include(ImportConfig)
configure_file(src/cpp/config.h.in config.h)

if (ZE_INSTALL)
    message(STATUS "Generating install")
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/proto DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} PATTERN "*.cpp" EXCLUDE)
    install(TARGETS cxx_proto
            PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

    foreach(cxx_service_name ${CXX_SERVICES})
        install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/${cxx_service_name} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} PATTERN "*.cpp" EXCLUDE)
        install(TARGETS "${cxx_service_name}_d" DESTINATION ${CMAKE_INSTALL_BIN_DIR})
        install(TARGETS ${cxx_service_name}
                PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
                LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
                ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
                RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
    endforeach()
endif()

if (ZE_TEST)
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
