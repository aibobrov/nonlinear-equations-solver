CXX=g++
GLUT=-framework GLUT -framework OpenGL
OPTIONS=-std=c++1z -Wall
TARGET=solver
all: solve
solve: main.o solvingEquation.o  plottingGraph.o fparser.o
	$(CXX) $(OPTIONS) *.o -o $(TARGET) $(GLUT)
main.o: main.cpp plottingGraph.cpp solvingEquation.cpp fparser/fparser.cc fparser/fparser.hh *.h
	$(CXX) $(OPTIONS) -c main.cpp $(GLUT)
solvingEquation.o: solvingEquation.cpp solvingEquation.h defines.h
	$(CXX) $(OPTIONS) -c solvingEquation.cpp
plottingGraph.o: plottingGraph.cpp plottingGraph.h defines.h
	$(CXX) $(OPTIONS) -c plottingGraph.cpp $(GLUT)
fparser.o: fparser/fparser.cc fparser/fparser.hh
	$(CXX) $(OPTIONS) -c fparser/fparser.cc
clean:
	rm *.o
