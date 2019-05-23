CMAKE_MINIMUM_REQUIRED (VERSION 2.8 )

project(tagen)

SET (SRC_FILES
        src/main.cpp
        src/JLFileManager.cpp
        )

SET (CMAKE_C_COMPILER "gcc" )

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

IF(!WIN64)
 FILE(REMOVE ${PROJECT_SOURCE_DIR}/include/dirent.h)

ADD_COMPILE_OPTIONS ( -g -Wall )
SET ( CMAKE_EXE_LINKER_FLAGS "-static -Wl,--gc-sections" )

add_executable(tagen ${SRC_FILES})


