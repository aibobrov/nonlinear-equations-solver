//
// Created by Artem Bobrov on 16.01.2018.
//

#ifndef SOLVER_ITERATIONS_WITHOUT_MAX_ITERATIONS_SOLVER_H
#define SOLVER_ITERATIONS_WITHOUT_MAX_ITERATIONS_SOLVER_H

#include "../base/solver.h"

class IterationsWithoutMaxIterationsSolver : public Solver{
public:
	explicit IterationsWithoutMaxIterationsSolver(const std::string &expression,double closeToRoot,
	                                              double eps, const std::string &sx);
	std::string name() override;

	double solve() override;
private:
	double _closeToRoot;
	double _eps;
	std::string s;
};

#endif //SOLVER_ITERATIONS_WITHOUT_MAX_ITERATIONS_SOLVER_H
