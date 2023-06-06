# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FirstGUI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FirstGUI_autogen.dir\\ParseCache.txt"
  "FirstGUI_autogen"
  )
endif()
