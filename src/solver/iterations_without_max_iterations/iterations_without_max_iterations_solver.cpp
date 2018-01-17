//
// Created by Artem Bobrov on 16.01.2018.
//

#include "iterations_without_max_iterations_solver.h"
IterationsWithoutMaxIterationsSolver::IterationsWithoutMaxIterationsSolver(const std::string &expression,
                                                                           double closeToRoot,
                                                                           double eps, const std::string &sx)
	: Solver(expression), _closeToRoot(closeToRoot), _eps(eps), s(sx) {

}

double IterationsWithoutMaxIterationsSolver::solve() {
	Parser sx;
	sx.Parse(s, "x");
	double xn = _closeToRoot;
	while (true) {
		xn = sx(xn);
		if (fabs(xn - sx(xn)) < _eps)
			break;
	}
	return xn;
}
std::string IterationsWithoutMaxIterationsSolver::name() {
	return "Iteration method without max iterations";
}

