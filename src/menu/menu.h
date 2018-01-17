//
// Created by Artem Bobrov on 16.01.2018.
//

#ifndef SOLVER_MENU_H
#define SOLVER_MENU_H

#include <iostream>

#include "../plotter/plotter.h"
#include "solvers.h"
#include "profiler.h"

class Menu {
public:
	Menu();
	~Menu();
public:
	void start();
private:
	enum class Method {
		Bisection = 1,
		Chord = 2,
		Iterations = 3,
		Newton = 4
	};
private:
	Method _getMethod();
	Solver *_getSolver(const std::string &expression, Method method);
private:
	Solver *_solver = nullptr;
	Plotter *_plotter = nullptr;
};

#endif //SOLVER_MENU_H
