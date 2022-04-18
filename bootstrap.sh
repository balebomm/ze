#! /bin/bash
echo -e "Bootstrap application before building"
if ! ls -AU "./external/vcpkg" | read _;
then
    git submodule update --init
fi
./external/vcpkg/bootstrap-vcpkg.sh &
VCPKG_BOOSTRAP_ID=$!
wait $VCPKG_BOOSTRAP_ID
VCPKG_EXIT_CODE=$?
VCPKG_EXIT_OK=0
if [ $VCPKG_EXIT_CODE -eq $VCPKG_EXIT_OK ]
then
    cmake -S . -B build/ -DCMAKE_INSTALL_PREFIX=../ze.image -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE="Debug"
else
    echo -e "Bootstrap vcpkg failed, please try later."
fi
