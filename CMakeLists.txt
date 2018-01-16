cmake_minimum_required(VERSION 3.7)

project(solver)

set(CMAKE_CXX_STANDARD 14)

include_directories(lib/gnuplot-iostream/ lib/parser/fparser)

set(SOURCE_FILES src/main.cpp
        lib/parser/fparser/fpoptimizer.cc
        lib/parser/fparser/fparser.cc
        lib/gnuplot-iostream/gnuplot-iostream.h
        src/solver/base/solver.cpp
        src/extra/parser.cpp
        src/extra/parser.h
        src/solver/bisection/bisection_solver.cpp
        src/solver/chord/chord_solver.cpp
        src/solver/newton_with_iterations/newton_with_iterations_solver.cpp
        src/solver/bisection/bisection_solver.h
        src/solver/chord/chord_solver.h
        src/solver/newton_with_iterations/newton_with_iterations_solver.h
        src/solver/newton_without_iterations/newton_without_iterations_solver.cpp
        src/solver/newton_without_iterations/newton_without_iterations_solver.h
        src/solver/iterations_with_max_iterations/iterations_with_max_iteration_solver.cpp
        src/solver/iterations_with_max_iterations/iterations_with_max_iteration_solver.h
        src/solver/iterations_without_max_iterations/iterations_without_max_iterations_solver.cpp
        src/solver/iterations_without_max_iterations/iterations_without_max_iterations_solver.h src/menu/menu.cpp src/menu/menu.h src/solver/solvers.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

IF (APPLE)
    INCLUDE_DIRECTORIES(/System/Library/Frameworks)
    FIND_LIBRARY(COCOA_LIBRARY Cocoa)
    FIND_LIBRARY(GLUT_LIBRARY GLUT)
    FIND_LIBRARY(OpenGL_LIBRARY OpenGL)
    MARK_AS_ADVANCED(COCOA_LIBRARY GLUT_LIBRARY OpenGL_LIBRARY)
    SET(EXTRA_LIBS ${COCOA_LIBRARY} ${GLUT_LIBRARY} ${OpenGL_LIBRARY})
ENDIF (APPLE)
target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})
