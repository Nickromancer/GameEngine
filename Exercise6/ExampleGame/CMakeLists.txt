# Game Only

file(GLOB_RECURSE 3DGame-src "*.h" "*.cpp")


add_executable(3DGame ${3DGame-src})

target_include_directories(3DGame PUBLIC ${MYENGINE_INCLUDE_DIR})

target_link_libraries(3DGame 3DEngine ${SGE_LIBRARIES})

# Copy project data to output path
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


IF (WIN32)
	## Copy dll's to output path
	file(COPY ${SGE_LIBRARIES_SHARED} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
	file(COPY ${SGE_LIBRARIES_SHARED} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
	file(COPY ${SGE_LIBRARIES_SHARED} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
ENDIF(WIN32)