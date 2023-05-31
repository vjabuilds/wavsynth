# MIT License 
# Copyright (c) 2018-Today Michele Adduci <adduci@tutanota.com>
#
# Project-related instructions

# Activate Testing, if given
if(BUILD_TESTING)
  enable_testing()
endif()

#####################################
# Define Targets
#####################################
add_subdirectory(wavlib)
add_subdirectory(wavsynth)

#####################################
# Define Install Targets
#####################################
install(TARGETS
  wavlib
  wavsynth
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  PUBLIC_HEADER DESTINATION include
)

install(
  FILES 
    ${CMAKE_SOURCE_DIR}/project/wavlib/include/wavlib.h 
    ${CMAKE_BINARY_DIR}/exports/wavlib_export.h
  DESTINATION 
    include/wavlib)

install(FILES  
  ${CMAKE_SOURCE_DIR}/LICENSE
DESTINATION .)