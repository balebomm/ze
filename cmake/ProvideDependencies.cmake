find_package(cppzmq CONFIG REQUIRED)
if (TARGET cppzmq)
    add_library(LibZmq ALIAS cppzmq)
endif()

find_package(nlohmann_json CONFIG REQUIRED)
if (TARGET nlohmann_json::nlohmann_json)
    add_library(LibNlohmannJson ALIAS nlohmann_json::nlohmann_json)
endif()
