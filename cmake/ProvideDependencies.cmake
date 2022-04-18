find_package(cppzmq CONFIG REQUIRED)
if (TARGET cppzmq)
    add_library(LibZmq ALIAS cppzmq)
endif()
