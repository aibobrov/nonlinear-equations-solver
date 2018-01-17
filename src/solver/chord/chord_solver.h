//
// Created by Artem Bobrov on 16.01.2018.
//

#ifndef SOLVER_CHORD_SOLVER_H
#define SOLVER_CHORD_SOLVER_H

#include "../base/solver.h"
#include <string>

class ChordSolver : public Solver {
public:
	explicit ChordSolver(const std::string &expression, double leftEdge, double rightEgde);
	double solve() override;
	std::string name() override;
private:
	double _left, _right;

};

#endif //SOLVER_CHORD_SOLVER_H
