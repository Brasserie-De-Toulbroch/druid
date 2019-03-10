# Find Bard
# ~~~~~~~~~

set(BARD_LIBRARY_NAMES bard)

find_library(BARD_LIBRARY
  NAMES ${BARD_LIBRARY_NAMES}
  PATHS
    /usr/lib
    /usr/local/lib
    "$ENV{LIB_DIR}/lib"
    "$ENV{LIB}"
)

FIND_PATH(BARD_INCLUDE_DIR NAMES ds18b20.h PATHS
  /usr/include/bard
  /usr/local/include/bard
  "$ENV{LIB_DIR}/include/bard"
  "$ENV{INCLUDE}"
)

IF (BARD_INCLUDE_DIR AND BARD_LIBRARY)
  SET(BARD_FOUND TRUE)
ENDIF (BARD_INCLUDE_DIR AND BARD_LIBRARY)

IF (BARD_FOUND)
  MESSAGE(STATUS "Found Bard: ${BARD_LIBRARY}")
ELSE (BARD_FOUND)
  MESSAGE(FATAL_ERROR "Could not find Bard")
ENDIF (BARD_FOUND)
