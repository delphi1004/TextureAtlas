CMAKE_MINIMUM_REQUIRED (VERSION 2.8 )

project(tagen)

set (SRC_FILES
        src/main.cpp
        src/JLFileManager.cpp
        src/JLTextureGen.cpp
        )

set (CMAKE_C_COMPILER "g++" )
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${PROJECT_SOURCE_DIR}/include)

if(WIN32)
	
   link_directories (${PROJECT_SOURCE_DIR}/lib/windows)

else()

   set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

   message("find opencv package!")

   find_package(OpenCV REQUIRED)

endif()
		
add_compile_options ( -g -Wall )
add_executable(${PROJECT_NAME} ${SRC_FILES})

if(WIN32)

  file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/Debug)
  file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/Release)

  file(COPY ${PROJECT_SOURCE_DIR}/include/dirent/dirent.h  DESTINATION ${PROJECT_SOURCE_DIR}/include)

  if(EXISTS ${CMAKE_BINARY_DIR}/Debug)
  	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
      		COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/lib/windows/opencv_world410d.dll ${CMAKE_BINARY_DIR}/Debug)
  endif()
       
  if(EXISTS ${CMAKE_BINARY_DIR}/Release)
  	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
      		COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/lib/windows/opencv_world410.dll ${CMAKE_BINARY_DIR}/Release)
  endif()
       
  target_link_libraries(${PROJECT_NAME} debug opencv_world410d optimized opencv_world410)

else()

   add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/bin)

   message("Link opencv library!")

   target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} )

   file(REMOVE ${PROJECT_SOURCE_DIR}/include/dirent.h)

endif()
