
SET(DUMB_SEARCH_PATHS
    /usr/local/
    /usr
    /opt
)

FIND_PATH(DUMB_INCLUDE_DIR dumb/dumb.h 
    HINTS ${DUMB_ROOT}
    PATH_SUFFIXES include include/dumb
    PATHS ${DUMB_SEARCH_PATHS}
)
FIND_LIBRARY(DUMB_LIBRARY dumb 
    HINTS ${DUMB_ROOT}
    PATH_SUFFIXES lib64 lib
    PATHS ${DUMB_SEARCH_PATHS}
)

IF(DUMB_INCLUDE_DIR AND DUMB_LIBRARY)
   SET(DUMB_FOUND TRUE)
ENDIF (DUMB_INCLUDE_DIR AND DUMB_LIBRARY)


IF(DUMB_FOUND)
    MESSAGE(STATUS "Found Dumb: ${DUMB_LIBRARY}")
ELSE(DUMB_FOUND)
    MESSAGE(WARNING "Could not find Dumb")
ENDIF(DUMB_FOUND)