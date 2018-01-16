//
// Created by Artem Bobrov on 16.01.2018.
//

#ifndef SOLVER_MENU_H
#define SOLVER_MENU_H

#include <iostream>

#include "../solver/solvers.h"

class Menu {
public:
	Menu() = default;
	~Menu();
public:
	inline void start();
private:
	enum class Method {
		Bisection = 1,
		Chord = 2,
		IterationsWithMaxIterations = 3,
		IterationsWithoutMaxIterations = 4,
		NewtonWithIterations = 5,
		NewtonWithoutIterations = 6

	};
private:
	Method _getMethod();
	Solver *_getSolver(const std::string &expression, Method method);
private:
	Solver *_solver = nullptr;
};

#endif //SOLVER_MENU_H
