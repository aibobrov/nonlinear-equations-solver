#ifndef JUSTGRAPH_DEFINES_H
#define JUSTGRAPH_DEFINES_H

// Std libs
#include <iostream>
#include <cmath>
#include <string>
#include <thread>

// OpenGL
#include <GLUT/glut.h>
#include <OpenGL/glext.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

// fParser
#include "fparser/fparser.hh"

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