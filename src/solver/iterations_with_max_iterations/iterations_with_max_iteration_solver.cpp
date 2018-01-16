//
// Created by Artem Bobrov on 16.01.2018.
//

#include "iterations_with_max_iteration_solver.h"

IterationsWithMaxIterationSolver::IterationsWithMaxIterationSolver(const std::string &expression, double closeToRoot,
                                                                   double eps,
                                                                   int amountIterations, const std::string &sx)
	: Solver(expression), _closeToRoot(closeToRoot), _eps(eps), _amountIterations(amountIterations), s(sx) {
}

double IterationsWithMaxIterationSolver::solve() {
	Parser sx;
	sx.Parse(s, "x");
	double xn;
	int i = 0;
	xn = _closeToRoot;
	while (true) {
		i++;
		xn = sx.Eval(&xn);
		if (fabs(xn - sx.Eval(&xn)) < _eps || i >= _amountIterations)
			break;
	}
	return xn;
}
std::string IterationsWithMaxIterationSolver::name() {
	return "Iteration method with max iterations";
}
