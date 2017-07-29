#!/bin/bash

# Set directory
DIRECTORY=`pwd`
      
echo " - Current path : " `pwd`

# Go parent
cd ..

# Set cmake
wget https://cmake.org/files/v3.9/cmake-3.9.0-Linux-x86_64.tar.gz -O  dl-cmake.tar.gz
tar xzf dl-cmake.tar.gz
mv cmake-* cmake
export PATH="${DIRECTORY}/../cmake/bin:$PATH"
         
echo " - CMake path : " `pwd`/cmake

# Install rapidjson
wget https://github.com/miloyip/rapidjson/archive/v1.1.0.tar.gz -O dl-rapidjson.tar.gz
tar xzf dl-rapidjson.tar.gz
mv rapidjson* rapidjson
cd rapidjson
cmake -DCMAKE_INSTALL_PREFIX=/usr .
make
sudo make install
echo " - RapidJson path : " `pwd`
cd ..


# Set clang
wget http://releases.llvm.org/4.0.1/clang+llvm-4.0.1-x86_64-linux-gnu-debian8.tar.xz -O dl-clang.tar.xz
tar xvfJ dl-clang.tar.xz
mv clang* clang
echo " - Clang path : " `pwd`/clang

# Build botan
wget https://botan.randombit.net/releases/Botan-2.1.0.tgz
tar xzf Botan-2.1.0.tgz
cd Botan-2.1.0
./configure.py
make
sudo make install
echo " - Botan path : " `pwd`
cd ..

# Go directory
cd ${DIRECTORY}
      
echo " - Current path : " `pwd`
