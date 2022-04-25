#! /bin/bash
SCRIPT_PATH=$(readlink -f ${BASH_SOURCE[0]})
WORKSPACE=$(dirname ${SCRIPT_PATH})

echo -e "Bootstrap application before building"
if ! ls -AU "./external/vcpkg" | read _;
then
    git submodule update --init
    cd external/vcpkg
    git checkout 2022.04.12
    cd ../..
fi
./external/vcpkg/bootstrap-vcpkg.sh &
VCPKG_BOOSTRAP_ID=$!
wait $VCPKG_BOOSTRAP_ID
VCPKG_EXIT_CODE=$?
VCPKG_EXIT_OK=0
export LD_LIBRARY_PATH=${WORKSPACE}/build/vcpkg_installed/x64-linux/lib
if [ $VCPKG_EXIT_CODE -eq $VCPKG_EXIT_OK ]
then
    cmake -S . -B build/ -DCMAKE_INSTALL_PREFIX=../ze.image -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE="Debug"
else
    echo -e "Bootstrap vcpkg failed, please try later."
fi
