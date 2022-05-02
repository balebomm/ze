file(GLOB ZE_EXAMPLE_COMMON_CXX RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} cpp/proto/proto/*.cc)
list(SORT ZE_EXAMPLE_COMMON_CXX)

add_library(example_common_cxx ${ZE_EXAMPLE_COMMON_CXX})

target_link_libraries(example_common_cxx PUBLIC LibZmq)
target_link_libraries(example_common_cxx PUBLIC LibGrpcGpr)
target_link_libraries(example_common_cxx PUBLIC LibGrpcUpb)
target_link_libraries(example_common_cxx PUBLIC LibGrpcGrpc)
target_link_libraries(example_common_cxx PUBLIC LibGrpcGrpcpp)
target_link_libraries(example_common_cxx PUBLIC LibGrpcReflection)

if (ZE_PEDANTIC)
    target_compile_options(example_common_cxx PUBLIC ${ZE_PEDANTIC_FLAGS})
endif()

if (ZE_WERROR)
    target_compile_options(example_common_cxx PUBLIC ${ZE_WERROR_FLAGS})
endif()

#
function(add_example_executable file_name)
    string(REGEX MATCH "cpp/src/(.+)/(.+).cpp" match_var "${file_name}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/example/${CMAKE_MATCH_1})
    set(executable_name ${CMAKE_MATCH_2})
    add_executable(${executable_name} ${file_name})
    target_link_libraries(${executable_name} PRIVATE example_common_cxx)
    target_include_directories(${executable_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/cpp/proto)
endfunction()

file(GLOB ZE_EXAMPLE_CXX RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} cpp/src/*/*.cpp)
list(SORT ZE_EXAMPLE_CXX)

foreach(file_name ${ZE_EXAMPLE_CXX})
    add_example_executable(${file_name})
endforeach()
