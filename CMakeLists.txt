CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)

PROJECT(DBusTest)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

SET(SERVICE_NAME "example.service.name")
SET(OBJECT_PATH "/my/service/objects")
SET(INTERFACE "example.system.interface")

configure_file(common.h.in common.h @ONLY)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

ADD_SUBDIRECTORY(client)
ADD_SUBDIRECTORY(gclient)
ADD_SUBDIRECTORY(daemon)
