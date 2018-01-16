//
// Created by Artem Bobrov on 16.01.2018.
//

#include "newton_without_iterations_solver.h"

NewtonWithoutIterationsSolver::NewtonWithoutIterationsSolver(const std::string &expression,
                                                             double closeToRoot,
                                                             double eps)
	: Solver(expression), _closeToRoot(closeToRoot), _eps(eps) {
}

double NewtonWithoutIterationsSolver::solve() {
	double x = _closeToRoot, dy, dx = 1e-7;
	double xPdx = x + dx;
	dy = (_expression.Eval(&xPdx) - _expression.Eval(&x)) / dx;
	double xPrevious = _closeToRoot + _eps * 10;
	for (; fabs(xPrevious - x) > _eps;) {
		xPrevious = x;
		x = x - _expression.Eval(&x) / dy;
	}
	return x;
}
std::string NewtonWithoutIterationsSolver::name() {
	return "Newton's method without max iterations";
}
