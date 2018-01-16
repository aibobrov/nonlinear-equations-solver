//
// Created by Artem Bobrov on 16.01.2018.
//

#ifndef SOLVER_NEWTON_WITH_MAX_ITERATION_H
#define SOLVER_NEWTON_WITH_MAX_ITERATION_H

#include "../base/solver.h"

class IterationsWithMaxIterationSolver : public Solver {
public:
	explicit IterationsWithMaxIterationSolver(const std::string &expression,
	                                          double closeToRoot,
	                                          double eps,
	                                          int amountIterations, const std::string& sx);
	double solve() override;
	std::string name() override;
private:
	double _closeToRoot;
	double _eps;
	int _amountIterations;
	std::string s;

};

#endif //SOLVER_NEWTON_WITH_MAX_ITERATION_H
