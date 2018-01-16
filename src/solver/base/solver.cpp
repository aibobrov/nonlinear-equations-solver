//
// Created by Artem Bobrov on 16.01.2018.
//
#include "solver.h"

Solver::Solver(const std::string &expression) {
	_expression.Parse(expression, "x");
	_expression.Optimize();
}