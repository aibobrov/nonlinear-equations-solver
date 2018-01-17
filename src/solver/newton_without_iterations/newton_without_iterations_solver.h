//
// Created by Artem Bobrov on 16.01.2018.
//

#ifndef SOLVER_NEWTON_WITHOUT_ITERATIONS_SOLVER_H
#define SOLVER_NEWTON_WITHOUT_ITERATIONS_SOLVER_H

#include "../base/solver.h"

class NewtonWithoutIterationsSolver : public Solver{
public:
	explicit NewtonWithoutIterationsSolver(const std::string &expression,double closeToRoot,
	                                       double eps);
	double solve() override;
	std::string name() override;
private:
	double _closeToRoot;
	double _eps;
};

#endif //SOLVER_NEWTON_WITHOUT_ITERATIONS_SOLVER_H
