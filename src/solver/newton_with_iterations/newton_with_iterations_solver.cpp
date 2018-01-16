//
// Created by Artem Bobrov on 16.01.2018.
//

#include "newton_with_iterations_solver.h"

NewtonWithIterationsSolver::NewtonWithIterationsSolver(const std::string &expression, double closeToRoot,
                                                       double eps,
                                                       int amountIterations)
	: Solver(expression), _closeToRoot(closeToRoot), _eps(eps), _amountIterations(amountIterations) {

}

double NewtonWithIterationsSolver::solve() {
	double x = _closeToRoot, dy, dx = 1e-5;
	double xPdx = x + dx;
	dy = (_expression.Eval(&xPdx) - _expression.Eval(&x)) / dx;
	double xPrevious = _closeToRoot + _eps * 2;
	for (int i = 0; fabs(xPrevious - x) > _eps; i++) {
		xPrevious = x;
		x = x - _expression.Eval(&x) / dy;
		if (i >= _amountIterations)
			break;
	}
	return x;
}
std::string NewtonWithIterationsSolver::name() {
	return "Newton's method with max iterations";
}
