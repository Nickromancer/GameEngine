# Engine Only

file(GLOB_RECURSE 3DEngine-src "*.cpp")
file(GLOB_RECURSE 3DEngine-hpp "*.h")

set(MYENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "" FORCE)

add_library(3DEngine ${3DEngine-src} ${3DEngine-hpp})
target_link_libraries(3DEngine ${SGE_LIBRARIES})

target_include_directories(3DEngine PUBLIC "Engine")
target_include_directories(3DEngine PUBLIC "3rdParty")
