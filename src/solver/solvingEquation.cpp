#include "solvingEquation.h"
#include <fstream>
double bisection(double left, double right){
	double medium = (right + left) / 2;
	if (expression.Eval(&medium) == 0)
		return medium;
	while (1) {
		medium = (right + left) / 2;
		if (medium == right || medium == left)
			break;
		if (expression.Eval(&medium) * expression.Eval(&right) < 0)
			left = medium;
		else
			right = medium;
	}
	return medium;
}

double hip(double left, double right){
	double c = (left * expression.Eval(&right) - right * expression.Eval(&left)) /
	           (expression.Eval(&right) - expression.Eval(&left));
	if (expression.Eval(&c) == 0)
		return c;
	while (1) {
		c = (left * expression.Eval(&right) - right * expression.Eval(&left)) /
		    (expression.Eval(&right) - expression.Eval(&left));
		if (c == left || c == right)
			break;
		if (expression.Eval(&c) * expression.Eval(&right) < 0)
			left = c;
		else
			right = c;
	}
	return c;
}

double newtonWithIteration(double closeToRoot, double eps, int amountIterations){
	double x = closeToRoot, dy, dx = 0.00001;
	double xPdx = x + dx;
	dy = (expression.Eval(&xPdx) - expression.Eval(&x)) / dx;
	double xPrevious = closeToRoot + eps * 2;
	for (int i = 0;fabs(xPrevious - x) > eps; i++) {
		xPrevious = x;
		x = x - expression.Eval(&x) / dy;
		if(i >= amountIterations )
			break;
	}
	return x;
}

double newtonWithoutIteration(double closeToRoot, double eps){
	double x = closeToRoot, dy, dx = 1e-7;
	double xPdx = x + dx;
	dy = (expression.Eval(&xPdx) - expression.Eval(&x)) / dx;
	double xPrevious = closeToRoot + eps * 10;
	std::ofstream t;
	t.open("out.txt");
	for (; fabs(xPrevious - x) > eps;) {
		xPrevious = x;
		x = x - expression.Eval(&x) / dy;
		t << x << " " << xPrevious << endl;
	}
	return x;
}

double iterationWithMaxIterations(double closeToRoot, double eps, int amountIterations, string s){
	ParserWithConsts Sx;
	Sx.Parse(s, "x");
	double xn;
	int i;
	xn = closeToRoot;
	i = 0;
	while (1) {
		i++;
		xn = Sx.Eval(&xn);
		if (fabs(xn - Sx.Eval(&xn)) < eps || i >= amountIterations)
			break;
	}
	return xn;
}

double iterationWithoutMaxIterations(double closeToRoot, double eps, string s){
	ParserWithConsts Sx;
	Sx.Parse(s, "x");
	double xn;
	xn = closeToRoot;
	
	while (1) {
		xn = Sx.Eval(&xn);
		if (fabs(xn - Sx.Eval(&xn)) < eps)
			break;
	}
	return xn;
}