cmake_minimum_required(VERSION 3.3)

project(Offer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

IF (WIN64)
    MESSAGE(STATUS "Now is windows")
ELSEIF (APPLE)
    MESSAGE(STATUS "Now is Apple systens.")
ELSEIF (UNIX)
    MESSAGE(STATUS "Now is UNIX-like OS's.")
ENDIF ()

#INCLUDE(CheckIncludeFiles)
#CHECK_INCLUDE_FILES(gtest.h HAVE_GTEST_INCLUDE_FILE)
#
#include(CheckLibraryExists)
#CHECK_LIBRARY_EXISTS(gtest TEST "" HAVE_GTEST)
#IF(HAVE_GTEST)
#    MESSAGE(INFO ${HAVE_GTEST})
#ENDIF()

aux_source_directory(${PROJECT_SOURCE_DIR}/include INCLUDE_FILES)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SOURCE_FILES)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)

add_subdirectory(gtest)
set(GTESTLIB
        gtest
        pthread)

LINK_LIBRARIES(${GTESTLIB})

#ADD_EXECUTABLE(main  main.cpp ${INCLUDE_FILES} ${SOURCE_FILES})
ADD_EXECUTABLE(threadpool app/simplethreadtest.cpp ${INCLUDE_FILES} ${SOURCE_FILES} include/ThreadPool.h src/ThreadPool.cpp)
ADD_EXECUTABLE(singleton app/singletontest.cpp ${INCLUDE_FILES} ${SOURCE_FILES})
ADD_EXECUTABLE(arrayfind app/arrayfindtest.cpp ${INCLUDE_FILES} ${SOURCE_FILES})
ADD_EXECUTABLE(repacespace app/repacespacetest.cpp ${INCLUDE_FILES} ${SOURCE_FILES})
ADD_EXECUTABLE(link app/link.cpp ${INCLUDE_FILES} ${SOURCE_FILES})
ADD_EXECUTABLE(minstack app/minstack.cpp ${INCLUDE_FILES} ${SOURCE_FILES} include/minstack.h)
ADD_EXECUTABLE(binarytree app/binarytree.cpp ${INCLUDE_FILES} ${SOURCE_FILES} include/binarytree.h)
ADD_EXECUTABLE(hwt app/wheeltimer.cpp ${INCLUDE_FILES} ${SOURCE_FILES} include/hashwheeltimer.h)
ADD_EXECUTABLE(sort app/sorttest.cpp ${INCLUDE_FILES} ${SOURCE_FILES} include/sort.h)
