//
// Created by Artem Bobrov on 15.01.2018.
//

#ifndef SOLVER_PARSER_H
#define SOLVER_PARSER_H

#include "parser/fparser/fparser.hh"

class Parser: public FunctionParser { 	// describing of out constants
public:
	Parser();

	double operator()(const double& value);
};

#endif //SOLVER_PARSER_H
