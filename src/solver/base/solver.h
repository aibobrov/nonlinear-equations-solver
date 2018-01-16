//
// Created by Artem Bobrov on 15.01.2018.
//

#ifndef SOLVER_SOLVER_H
#define SOLVER_SOLVER_H

#include "../../extra/parser.h"
#include <string>

class Solver {
public:
	explicit Solver(const std::string &expression);

	virtual double solve() = 0;

	virtual std::string name() = 0;
protected:
	Parser _expression;
};

#endif //SOLVER_SOLVER_H
