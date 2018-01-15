#ifndef JUSTGRAPH_DEFINES_H
#define JUSTGRAPH_DEFINES_H

// Std libs
#include <iostream>
#include <cmath>
#include <string>
#include <thread>

// OpenGL
#include <GLUT/glut.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/OpenGL.h>

// fParser
#include "../lib/fparser/fparser.hh"

#define MIN(a, b) ((a)<(b))? (a):(b)

// used names in namespaces
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::thread;

class ParserWithConsts : public FunctionParser {
public:
	ParserWithConsts(){ // describing of out constants
		AddConstant("pi", M_PI);
		AddConstant("e", exp(1));
	}
};

extern ParserWithConsts expression; // function parser (later our parsed function)

#endif //JUSTGRAPH_DEFINES_H