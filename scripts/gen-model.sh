#! /bin/bash

SCRIPT_FILE_PATH=$(readlink -f ${BASH_SOURCE[0]})
SCRIPT_FOLDER_PATH=$(dirname ${SCRIPT_FILE_PATH})
WORKSPACE=$(dirname ${SCRIPT_FOLDER_PATH})
PROTOC_EXE_PATH=${WORKSPACE}/build/vcpkg_installed/x64-linux/tools/protobuf/protoc
GRPC_CPP_PLUGIN=${WORKSPACE}/build/vcpkg_installed/x64-linux/tools/grpc/grpc_cpp_plugin
SHARED_LIB_PATH=${WORKSPACE}/build/vcpkg_installed/x64-linux/lib

MODAL_SRC=${WORKSPACE}/model
MODAL_EXAMPLE=${WORKSPACE}/example/model
PROTO_EXAMPLE_CPP=${WORKSPACE}/example/cpp/proto/proto
PROTO_SRC_CPP=${WORKSPACE}/src/cpp/proto/proto
PROTO_SRC_JS_WEB=${WORKSPACE}/web/proto

CAN_GENERATE_MODEL="ON"

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

    #
    if [ $CAN_GENERATE_MODEL == "OFF" ]
    then
        echo "Failed to execute command because project is not built yet"
        exit
    fi
}

GenCppModel()
{
    CheckBuildSystem

    for proto_file in ${MODAL_SRC}/*
    do
        ${PROTOC_EXE_PATH} -I=${MODAL_SRC} ${proto_file} --grpc_out=${PROTO_SRC_CPP} --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN}
        ${PROTOC_EXE_PATH} -I=${MODAL_SRC} ${proto_file} --cpp_out=${PROTO_SRC_CPP}
    done
}

GenJsWeb()
{
    CheckBuildSystem
    
    for proto_file in ${MODAL_SRC}/*
    do
        ${PROTOC_EXE_PATH} -I=${MODAL_SRC} ${proto_file} --js_out=import_style=commonjs,binary:${PROTO_SRC_JS_WEB} --grpc-web_out=import_style=typescript,mode=grpcweb:${PROTO_SRC_JS_WEB}
    done
}

GenExampleCppModel()
{
    CheckBuildSystem

    for proto_file in ${MODAL_EXAMPLE}/*
    do
        ${PROTOC_EXE_PATH} -I=${MODAL_EXAMPLE} ${proto_file} --grpc_out=${PROTO_EXAMPLE_CPP} --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN}
        ${PROTOC_EXE_PATH} -I=${MODAL_EXAMPLE} ${proto_file} --cpp_out=${PROTO_EXAMPLE_CPP}
    done
}

Help()
{
    echo -e "options:"
    echo -e "\t--all\t\t\t\t\tGenerate all language module"
    echo -e "\t--clear\t\t\t\t\tClear all target language module"
    echo -e "\t--lang_cpp\t\t\t\tGenerate cpp model in src/proto"
    echo -e "\t--lang_js_web\t\t\t\tGenerate js web model in web/js/proto"
    echo -e "\t--example_lang_cpp\t\t\tGenerate exampl cpp model in example/cpp/src/proto"
}

Clear()
{
    rm -rf ${PROTO_EXAMPLE_CPP}/*
    rm -rf ${PROTO_SRC_CPP}/*
    rm -rf ${PROTO_SRC_JS_WEB}/*
    echo -e "Cleared all model"
}

All()
{
    GenCppModel
    GenJsWeb
    GenExampleCppModel
    echo -e "Generated all target language model"
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
                lang_js_web)
                    GenJsWeb
                    exit;;
                example_lang_cpp)
                    GenExampleCppModel
                    exit;;
                help)
                    Help
                    exit;;
                all)
                    All
                    exit;;
                clear)
                    Clear
                    exit;;
                *)
                    echo "Invalid option"
                    exit;;
            esac;;
        h)
            Help
            exit;;
        c)
            Clear
            exit;;
        a)
            All
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
