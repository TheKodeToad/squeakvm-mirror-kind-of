# Yes, it's true: you can write makefiles in COBOL.
# 
# Last edited: 2009-08-16 11:25:34 by piumarta on emilia-2.local

PROJECT (squeak)

CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

IF (NOT DEFINED VM_HOST OR NOT DEFINED VM_VERSION OR NOT DEFINED SQ_VERSION)
  MESSAGE (FATAL_ERROR "
    You MUST NOT run CMake directly the first time you configure a build.
    Run 'platforms/unix/cmake/configure' from within your build directory."
  )
ENDIF (NOT DEFINED VM_HOST OR NOT DEFINED VM_VERSION OR NOT DEFINED SQ_VERSION)

SET (bld    ${CMAKE_BINARY_DIR})
SET (unix   ${CMAKE_SOURCE_DIR})
SET (config ${unix}/cmake)

GET_CMAKE_PROPERTY (vars VARIABLES)
FOREACH (opt ${vars})
  IF (opt MATCHES "OPT_.*")
    STRING (REGEX REPLACE "OPT_(.*)" "\\1" var ${opt})
    #MESSAGE (STATUS "Setting ${var}=${${opt}}")
    SET (${var} ${${opt}})
  ENDIF ()
ENDFOREACH (opt)

GET_FILENAME_COMPONENT (cross ${unix}/../Cross REALPATH)

IF (OPT_src)
  GET_FILENAME_COMPONENT (src ${OPT_src} ABSOLUTE)
ELSE (SRC)
  SET (src  ${unix}/src)
ENDIF (OPT_src)

IF (NOT EXISTS ${src})
  MESSAGE (FATAL_ERROR "
    Source directory ${src} does not exist."
  )
ENDIF (NOT EXISTS ${src})

INCLUDE (${config}/Utils.cmake)
INCLUDE (${config}/Plugins.cmake)

STRING (REGEX REPLACE "(.*)-(.*)-(.*)" "\\1" VM_HOST_CPU    ${VM_HOST})
STRING (REGEX REPLACE "(.*)-(.*)-(.*)" "\\2" VM_HOST_VENDOR ${VM_HOST})
STRING (REGEX REPLACE "(.*)-(.*)-(.*)" "\\3" VM_HOST_OS     ${VM_HOST})

IF (OPT_CFLAGS)
  SET (CMAKE_C_FLAGS "${OPT_CFLAGS}")
ENDIF (OPT_CFLAGS)

IF (NOT CMAKE_C_FLAGS)
  IF (CMAKE_COMPILER_IS_GNUCC)
    IF     (${VM_HOST_CPU} MATCHES "i.86")
      SET (CMAKE_C_FLAGS "-g -O2 -fomit-frame-pointer")
    ELSEIF (${VM_HOST_CPU} STREQUAL "ppc" OR ${VM_HOST_CPU} STREQUAL "powerpc")
      SET (CMAKE_C_FLAGS "-g -O3 -funroll-loops -mcpu=750 -mno-fused-madd")
    ENDIF ()
  ENDIF (CMAKE_COMPILER_IS_GNUCC)
ENDIF (NOT CMAKE_C_FLAGS)

IF (NOT CMAKE_C_FLAGS)
  SET (CMAKE_C_FLAGS "${CMAKE_C_FLAGS_RELEASE}")
ENDIF (NOT CMAKE_C_FLAGS)

MACRO (USE_LIBRARY lib)
  LIST (APPEND squeak_libs "${lib}")
ENDMACRO (USE_LIBRARY)

MACRO (USE_FRAMEWORK fwk)
  USE_LIBRARY ("-framework ${fwk}")
ENDMACRO (USE_FRAMEWORK)

MACRO (CONFIG_DEFINE var)
  LIST (APPEND config_vars "${var}")
ENDMACRO (CONFIG_DEFINE var)

SET (UNIX 1)
CONFIG_DEFINE (UNIX)

INCLUDE (${unix}/vm/config.cmake)

CONFIGURE_PLUGINS ()

LIST (REMOVE_DUPLICATES config_vars)
FILE (WRITE ${bld}/config.h.in "")
FOREACH (var ${config_vars})
  FILE (APPEND ${bld}/config.h.in "#cmakedefine ${var} @${var}@\n")
ENDFOREACH (var)

CONFIGURE_FILE (${bld}/config.h.in ${bld}/config.h)

INCLUDE (${unix}/vm/build.cmake)

BUILD_PLUGINS ()

GET_CMAKE_PROPERTY (tmp VARIABLES)
LIST (REMOVE_ITEM tmp tmp)
LIST (SORT tmp)
FILE (WRITE ${bld}/config.status "")
FOREACH (var ${tmp})
  FILE (APPEND ${bld}/config.status "${var}=${${var}}\n")
ENDFOREACH ()