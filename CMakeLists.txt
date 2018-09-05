cmake_minimum_required(VERSION 3.3)

project(Utili)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

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
ADD_EXECUTABLE(threadpool  app/simplethreadtest.cpp ${INCLUDE_FILES} ${SOURCE_FILES})
ADD_EXECUTABLE(singleton  app/singletontest.cpp ${INCLUDE_FILES} ${SOURCE_FILES})
ADD_EXECUTABLE(arrayfind  app/arrayfindtest.cpp ${INCLUDE_FILES} ${SOURCE_FILES})
ADD_EXECUTABLE(repacespace  app/repacespacetest.cpp ${INCLUDE_FILES} ${SOURCE_FILES})
