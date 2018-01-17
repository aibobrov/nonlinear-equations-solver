//
// Created by Artem Bobrov on 17.01.2018.
//

#ifndef SOLVER_PLOTTER_H
#define SOLVER_PLOTTER_H

#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <boost/algorithm/string/replace.hpp>

#include "gnuplot/GNUPlot.h"

class Plotter {
public:
	Plotter() {
	}

	~Plotter() = default;

	void plot(std::string function);
private:
	void _format(std::string &function);
};

#endif //SOLVER_PLOTTER_H
