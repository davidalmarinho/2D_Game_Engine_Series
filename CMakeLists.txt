cmake_minimum_required(VERSION 3.20)

project(Stunner)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

# Search for the external libs.
find_package(PkgConfig REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(${CMAKE_PROJECT_NAME} ${MY_SOURCES})

set_target_properties(${PROJECT_NAME}
PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
  RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
  RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
  RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

target_include_directories(${CMAKE_PROJECT_NAME}
  PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/include/"
)

# Link the external libs to the program.
target_link_libraries(${CMAKE_PROJECT_NAME}
  PUBLIC
  GLEW::GLEW
  glfw
)

# Copy the assets folder into the build directory.
add_custom_target(copy_assets
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
)

add_dependencies(${PROJECT_NAME} copy_assets)