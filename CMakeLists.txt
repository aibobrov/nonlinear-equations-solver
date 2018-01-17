cmake_minimum_required(VERSION 3.7)

project(solver)

set(CMAKE_CXX_STANDARD 14)

include_directories(lib src/extra src/solver)

set(SOURCE_FILES
        lib/parser/fparser/fpoptimizer.cc
        lib/parser/fparser/fparser.cc
        lib/gnuplot/GNUPlot.cpp
        src/main.cpp
        src/extra/parser.cpp
        src/extra/parser.h
        src/extra/profiler.cpp
        src/extra/profiler.h
        src/menu/menu.cpp
        src/menu/menu.h
        src/solver/solvers.h
        src/solver/base/solver.cpp
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
        src/solver/iterations_without_max_iterations/iterations_without_max_iterations_solver.h
        src/plotter/plotter.cpp
        src/plotter/plotter.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(Boost REQUIRED COMPONENTS system iostreams)
include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})