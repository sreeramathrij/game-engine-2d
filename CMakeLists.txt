cmake_minimum_required(VERSION 3.16)
project(sfml-learning)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
  SFML::Graphics
  SFML::Window
  SFML::System
  SFML::Audio
)
