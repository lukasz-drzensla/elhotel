# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ELHotel_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ELHotel_autogen.dir\\ParseCache.txt"
  "ELHotel_autogen"
  )
endif()
