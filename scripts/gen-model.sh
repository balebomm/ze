#! /bin/bash

SCRIPT_FILE_PATH=$(readlink -f ${BASH_SOURCE[0]})
SCRIPT_FOLDER_PATH=$(dirname ${SCRIPT_FILE_PATH})
WORKSPACE=$(dirname ${SCRIPT_FOLDER_PATH})
PROTOC_EXE_PATH=${WORKSPACE}/build/vcpkg_installed/x64-linux/tools/protobuf/protoc
GRPC_CPP_PLUGIN=${WORKSPACE}/build/vcpkg_installed/x64-linux/tools/grpc/grpc_cpp_plugin
SHARED_LIB_PATH=${WORKSPACE}/build/vcpkg_installed/x64-linux/lib
CAN_GENERATE_MODEL="ON"
MODEL_FOLDER_PATH=${WORKSPACE}/model
TARGET_CPP_FOLDER_PATH=${WORKSPACE}/src/proto

CheckBuildSystem()
{
    if [ ! -f ${PROTOC_EXE_PATH} ]
    then
        echo ${PROTOC_EXE_PATH}
        CAN_GENERATE_MODEL="OFF"
    fi

    if [ ! -f ${GRPC_CPP_PLUGIN} ]
    then
        echo ${GRPC_CPP_PLUGIN}
        CAN_GENERATE_MODEL="OFF"
    fi

    if [ ! -d ${SHARED_LIB_PATH} ]
    then
        echo ${SHARED_LIB_PATH}
        CAN_GENERATE_MODEL="OFF"
    fi
}

GenCppModel()
{
    CheckBuildSystem
    if [ $CAN_GENERATE_MODEL == "OFF" ]
    then
        echo "Failed to execute command because project is not built yet"
        exit
    fi

    for proto_file in ${MODEL_FOLDER_PATH}/*
    do
        ${PROTOC_EXE_PATH} -I ${MODEL_FOLDER_PATH} --grpc_out=${TARGET_CPP_FOLDER_PATH} --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN} ${proto_file}
        ${PROTOC_EXE_PATH} -I ${MODEL_FOLDER_PATH} --cpp_out=${TARGET_CPP_FOLDER_PATH} ${proto_file}
    done
}

Help()
{
    echo -e "options:"
    echo -e "\t--lang_cpp\t\t\t\tGenerate cpp model in src/proto"
}

while getopts "h-:" option;
do
    case $option
    in
        -)
            case "${OPTARG}"
            in
                lang_cpp)
                    GenCppModel
                    exit;;
                help)
                    Help
                    exit;;
                *)
                    echo "Invalid option"
                    exit;;
            esac;;
        h)
            Help
            exit;;
        *)
            echo "Invalid option"
            exit;;
    esac
done

if [ -z $1 ]
then
    Help
fi
