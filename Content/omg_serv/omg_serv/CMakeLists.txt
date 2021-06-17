# CMakeList.txt : CMake project for omg_serv, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("omg_serv")

# Add source to this project's executable.
add_library (omg_serv "omg_serv.cpp" "omg_serv.h" "SerialPort.h" "SerialPort.cpp")

# TODO: Add tests and install targets if needed.
