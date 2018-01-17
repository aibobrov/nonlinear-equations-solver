//
// Created by Artem Bobrov on 15.01.2018.
//

#include "parser.h"
Parser::Parser(): FunctionParser() {
	AddConstant("pi", M_PI);
	AddConstant("e", exp(1));
}
double Parser::operator()(const double &value) {
	return this->Eval(&value);
}
