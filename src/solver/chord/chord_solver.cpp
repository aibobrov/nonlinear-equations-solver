//
// Created by Artem Bobrov on 16.01.2018.
//

#include "chord_solver.h"

ChordSolver::ChordSolver(const std::string &expression, double leftEdge, double rightEgde)
	: Solver(expression), _left(leftEdge), _right(rightEgde) {
}

double ChordSolver::solve() {
	double c = (_left * _expression(_right) - _right * _expression(_left)) /
		(_expression(_right) - _expression(_left));
	if (_expression(c) == 0)
		return c;
	while (true) {
		c = (_left * _expression(_right) - _right * _expression(_left)) /
			(_expression(_right) - _expression(_left));
		if (c == _left || c == _right)
			break;
		if (_expression(c) * _expression(_right) < 0)
			_left = c;
		else
			_right = c;
	}
	return c;
}
std::string ChordSolver::name() {
	return "Chord method";
}
