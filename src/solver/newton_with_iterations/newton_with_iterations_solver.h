//
// Created by Artem Bobrov on 16.01.2018.
//

#ifndef SOLVER_NEWTON_WITH_ITERATIONS_SOLVER_H
#define SOLVER_NEWTON_WITH_ITERATIONS_SOLVER_H

#include "../base/solver.h"

#include <string>

class NewtonWithIterationsSolver : public Solver {
public:
	explicit NewtonWithIterationsSolver(const std::string &expression,
	                                    double closeToRoot,
	                                    double eps,
	                                    int amountIterations);
	double solve() override;
	std::string name() override;
private:
	double _closeToRoot;
	double _eps;
	int _amountIterations;
};

#endif //SOLVER_NEWTON_WITH_ITERATIONS_SOLVER_H
