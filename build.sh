#!/bin/bash

## Managing default directories, args etc...

ORIGIN=$(pwd)

DEFAULT_CMAKE_BUILD_DIR=".build"
DEFAULT_OUTPUT_DIR="bin"

CMAKE_BUILD_DIR=${1}
OUTPUT_DIR=${2}

REPO_BUILD_DIR="build-repo"
SOURCE_BUILD_DIR="build-source"

##
##	REPO
##

cd ${REPO_BUILD_DIR}

# Making sure directories are there

if [ -z "${CMAKE_BUILD_DIR}" ]; then
	CMAKE_BUILD_DIR=${DEFAULT_CMAKE_BUILD_DIR}
fi

if [ -z "${OUTPUT_DIR}" ]; then
	OUTPUT_DIR=${DEFAULT_OUTPUT_DIR}
fi

if [ ! -d "$CMAKE_BUILD_DIR" ]; then
  mkdir ${CMAKE_BUILD_DIR}
fi

if [ ! -d "$OUTPUT_DIR" ]; then
  mkdir ${OUTPUT_DIR}
fi

cd ${CMAKE_BUILD_DIR}

# Build

cmake ..
make
mv prog ../${OUTPUT_DIR}


cd ../..

##
##	SOURCE
##

cd ${SOURCE_BUILD_DIR}

## Making sure directories are there

if [ -z "${CMAKE_BUILD_DIR}" ]; then
	CMAKE_BUILD_DIR=${DEFAULT_CMAKE_BUILD_DIR}
fi

if [ -z "${OUTPUT_DIR}" ]; then
	OUTPUT_DIR=${DEFAULT_OUTPUT_DIR}
fi

if [ ! -d "$CMAKE_BUILD_DIR" ]; then
  mkdir ${CMAKE_BUILD_DIR}
fi

if [ ! -d "$OUTPUT_DIR" ]; then
  mkdir ${OUTPUT_DIR}
fi

cd ${CMAKE_BUILD_DIR}

cmake ..
make
mv prog ../${OUTPUT_DIR}

cd ../..