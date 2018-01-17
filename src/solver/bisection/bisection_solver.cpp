//
// Created by Artem Bobrov on 16.01.2018.
//

#include "bisection_solver.h"
BisectionSolver::BisectionSolver(const std::string &expression, double leftEdge, double rightEgde)
	: Solver(expression), _left(leftEdge), _right(rightEgde) {
}
double BisectionSolver::solve() {
	double medium = (_right + _left) / 2;
	if (_expression(medium) == 0)
		return medium;
	while (true) {
		medium = (_right + _left) / 2;
		if (medium == _right || medium == _left)
			break;
		if (_expression(medium) * _expression(_right) < 0)
			_left = medium;
		else
			_right = medium;
	}
	return medium;
}
std::string BisectionSolver::name() {
	return "Bisection method";
}
