cmake_minimum_required(VERSION 3.28)
project(Quad LANGUAGES CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 3.0.1
)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(SFML_BUILD_DOC          OFF CACHE BOOL "" FORCE)   
set(SFML_BUILD_TEST_SUITE   OFF CACHE BOOL "" FORCE)   
set(SFML_BUILD_EXAMPLES     OFF CACHE BOOL "" FORCE)   
FetchContent_MakeAvailable(SFML)

file(GLOB SRC "src/*.cpp")
add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME}
   PRIVATE
    SFML::Graphics
    SFML::Audio   
    SFML::Network 
)
