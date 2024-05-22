# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "Minopoly/CMakeFiles/Minopoly_autogen.dir/AutogenUsed.txt"
  "Minopoly/CMakeFiles/Minopoly_autogen.dir/ParseCache.txt"
  "Minopoly/Minopoly_autogen"
  "game-state/CMakeFiles/game-state_autogen.dir/AutogenUsed.txt"
  "game-state/CMakeFiles/game-state_autogen.dir/ParseCache.txt"
  "game-state/game-state_autogen"
  )
endif()
