#!/bin/bash

# Build script for linux.cpp with GLAD and GLFW

echo "Compiling linux.cpp..."

g++ linux.cpp include/src/gl.c -Iinclude/include -lglfw -lGL -o app

if [ $? -eq 0 ]; then
    echo "Build successful! Run with: ./app"
else
    echo "Build failed!"
    exit 1
fi
