CMAKE_MINIMUM_REQUIRED (VERSION 2.8 )

project(tagen)

SET (SRC_FILES
        src/main.cpp
        src/JLFileManager.cpp
        src/JLTextureGen.cpp
        )

SET (CMAKE_C_COMPILER "gcc" )

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)



LINK_DIRECTORIES (${PROJECT_SOURCE_DIR}/lib/windows)

ADD_COMPILE_OPTIONS ( -g -Wall )
SET (CMAKE_EXE_LINKER_FLAGS "-static -Wl,--gc-sections" )

add_executable(tagen ${SRC_FILES})

TARGET_LINK_LIBRARIES(tagen debug opencv_world410d optimized opencv_world410)


