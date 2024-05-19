cmake_minimum_required(VERSION 3.25)
project(CLION)

set(CMAKE_CXX_STANDARD 23)

# Create the executable target
add_executable(CLION main.cpp)

# Link against the Windows libraries necessary for Bluetooth
target_link_libraries(CLION Bthprops Ws2_32)
