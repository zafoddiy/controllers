# project-root/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(Controllers)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Include the include directory for shared headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add subdirectories for libraries and executables
add_subdirectory(lib)
add_subdirectory(src)