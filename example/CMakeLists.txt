file(GLOB EXAMPLE_PROTO_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} model/*.proto)
list(SORT EXAMPLE_PROTO_SRCS)

make_directory(${CMAKE_CURRENT_BINARY_DIR}/proto)
foreach(example_proto_src ${EXAMPLE_PROTO_SRCS})
    string(REGEX MATCH "model/(.+).proto" match_var ${example_proto_src})
    set(example_cxx_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/proto/${CMAKE_MATCH_1}.pb.cc")
    set(example_cxx_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/proto/${CMAKE_MATCH_1}.pb.h")
    set(example_cxx_grpc_srcs  "${CMAKE_CURRENT_BINARY_DIR}/proto/${CMAKE_MATCH_1}.grpc.pb.cc")
    set(example_cxx_grpc_hdrs  "${CMAKE_CURRENT_BINARY_DIR}/proto/${CMAKE_MATCH_1}.grpc.pb.h")

    add_custom_command(
        OUTPUT ${example_cxx_proto_srcs} ${example_cxx_proto_hdrs} ${example_cxx_grpc_srcs} ${example_cxx_grpc_hdrs}
        COMMAND ${PROTOBUF_PROTOC}
        ARGS --grpc_out=${CMAKE_CURRENT_BINARY_DIR}/proto
            --cpp_out=${CMAKE_CURRENT_BINARY_DIR}/proto 
            -I=${CMAKE_CURRENT_SOURCE_DIR}/model
            --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/${example_proto_src}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${example_proto_src}
    )

    add_library(proto-${CMAKE_MATCH_1} ${example_cxx_proto_srcs} ${example_cxx_grpc_srcs})
    target_include_directories(proto-${CMAKE_MATCH_1} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/proto>")

    target_link_libraries(proto-${CMAKE_MATCH_1} PUBLIC LibProtobufProtobuf)
    target_link_libraries(proto-${CMAKE_MATCH_1} PUBLIC LibGrpcGrpcpp)
    target_link_libraries(proto-${CMAKE_MATCH_1} PUBLIC LibGrpcReflection)
endforeach()

#
function(add_example_executable file_name)
    string(REGEX MATCH "cpp/(.+)/(.+).cpp" match_var "${file_name}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/example/${CMAKE_MATCH_1})
    set(executable_name ${CMAKE_MATCH_2})
    add_executable(${executable_name} ${file_name})

    target_link_libraries(${executable_name} PRIVATE proto-employee)
    target_link_libraries(${executable_name} PRIVATE proto-greet)
    target_link_libraries(${executable_name} PRIVATE proto-route)
    target_link_libraries(${executable_name} PRIVATE LibZmq)

    target_include_directories(${executable_name} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

    if (ZE_PEDANTIC)
        target_compile_options(${executable_name} PRIVATE ${ZE_PEDANTIC_FLAGS})
    endif()

    if (ZE_WERROR)
        target_compile_options(${executable_name} PRIVATE ${ZE_WERROR_FLAGS})
    endif()
endfunction()

file(GLOB ZE_EXAMPLE_CXX RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} cpp/*/*.cpp)
list(SORT ZE_EXAMPLE_CXX)

foreach(file_name ${ZE_EXAMPLE_CXX})
    add_example_executable(${file_name})
endforeach()
