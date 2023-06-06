# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MyGUIprogramm_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MyGUIprogramm_autogen.dir\\ParseCache.txt"
  "MyGUIprogramm_autogen"
  )
endif()
