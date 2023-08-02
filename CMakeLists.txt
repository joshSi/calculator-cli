cmake_minimum_required(VERSION 3.12)
project(YourProjectName)  # Replace "YourProjectName" with your actual project name

# Set the C++ standard (change it if you are using a different version)
set(CMAKE_CXX_STANDARD 17)

# Add the include directories
include_directories(include)

# Add the source files to the project
file(GLOB_RECURSE SOURCES src/*.cpp)

# Add an executable for your project
add_executable(${PROJECT_NAME} ${SOURCES})

# Optionally, if you want to organize your source files properly in an IDE like Visual Studio
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})
