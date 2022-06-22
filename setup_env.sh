#!/bin/sh
git -C vcpkg pull --unshallow
git -C vcpkg describe --tags
git -C vcpkg rev-parse --short HEAD

./vcpkg/bootstrap-vcpkg.sh
cmake -B build -DCMAKE_TOOLCHAIN_FILE=vcpkg/scripts/buildsystems/vcpkg.cmake
