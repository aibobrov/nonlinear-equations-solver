#ifndef JUSTGRAPH_SOLVINGEQUATION_H
#define JUSTGRAPH_SOLVINGEQUATION_H

#include "defines.h"

// bisection method
double bisection(double left, double right);

// hip method
double hip(double left, double right);

// Newton's method with max iteration count
double newtonWithIteration(double closeToRoot, double eps, int amountIterations);

// Newton's method without max iteration count
double newtonWithoutIteration(double closeToRoot, double eps);

// Iteration method with max iteration count
double iterationWithMaxIterations(double closeToRoot, double eps, int amountIterations, string s);

// Iteration method without max iteration count
double iterationWithoutMaxIterations(double closeToRoot, double eps, string s);

#endif //JUSTGRAPH_SOLVINGEQUATION_H