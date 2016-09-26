cmake_minimum_required(VERSION 2.8)
INCLUDE(CMakeForceCompiler)
set(ARM_PREFIX arm-frc-linux-gnueabi)
set(CMAKE_SYSTEM_NAME Linux)

IF (WIN32)
    CMAKE_FORCE_CXX_COMPILER(C:/frc/bin/arm-frc-linux-gnueabi-g++.exe GNU)
    CMAKE_FORCE_C_COMPILER(C:/frc/bin/arm-frc-linux-gnueabi-gcc.exe GNU)
ELSE()
    CMAKE_FORCE_CXX_COMPILER(${ARM_PREFIX}-g++ GNU)
    CMAKE_FORCE_C_COMPILER(${ARM_PREFIX}-gcc GNU)
ENDIF()

set(CMAKE_CXX_FLAGS "-std=c++1y -Wformat=2 -Wall -Wextra -Werror -pedantic -Wno-psabi" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -g" CACHE STRING "" FORCE) # still want debugging for release?
