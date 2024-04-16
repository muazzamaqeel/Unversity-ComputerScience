# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Bluetooth_Custom_HID_autogen"
  "CMakeFiles\\Bluetooth_Custom_HID_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Bluetooth_Custom_HID_autogen.dir\\ParseCache.txt"
  )
endif()
