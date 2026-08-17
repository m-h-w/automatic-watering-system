cmake_minimum_required(VERSION 3.16)

set(EXTRA_COMPONENT_DIRS ${CMAKE_SOURCE_DIR}/control-loop ${CMAKE_SOURCE_DIR}/webserver)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(automatic-watering-system)
