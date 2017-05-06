cmake_minimum_required(VERSION 3.7)

project(Solver)#PROJECT NAME

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp fparser/fparser.cc defines.h plottingGraph.cpp plottingGraph.h solvingEquation.cpp solvingEquation.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
IF(APPLE)
    INCLUDE_DIRECTORIES ( /System/Library/Frameworks )
    FIND_LIBRARY(COCOA_LIBRARY Cocoa)
    FIND_LIBRARY(GLUT_LIBRARY GLUT )
    FIND_LIBRARY(OpenGL_LIBRARY OpenGL )
    MARK_AS_ADVANCED (COCOA_LIBRARY GLUT_LIBRARY OpenGL_LIBRARY)
    SET(EXTRA_LIBS ${COCOA_LIBRARY} ${GLUT_LIBRARY} ${OpenGL_LIBRARY})
ENDIF (APPLE)
target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})
