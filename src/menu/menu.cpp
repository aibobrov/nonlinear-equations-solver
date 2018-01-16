//
// Created by Artem Bobrov on 16.01.2018.
//

#include "menu.h"

Menu::~Menu() {
//	delete _solver;
}

void Menu::start() {
	std::string expression_string;
	std::cout << "Type the function to find its root\ny = ";
	getline(std::cin, expression_string); // our main string function
	Method method = _getMethod();
	_solver = _getSolver(expression_string, method);

}
Menu::Method Menu::_getMethod() {
	std::cout << "Choose the method for solving equations:" << std::endl;
	std::cout << "\t1)Bisection method\n"
		"\t2)Chord method\n"
		"\t3)Iteration method with max iterations\n"
		"\t4)Iteration method without max iterations\n"
		"\t5)Newton's method with max iterations"
		"\t6)Newton's method without max iterations"
	          << std::endl;
	std::cout << "Type choosen number" << std::endl;
	int value;
	std::cin >> value;

	if (value < 1 || value > 6)
		throw std::invalid_argument("Incorrent method number");

	return static_cast<Method>(value);
}

Solver *Menu::_getSolver(const std::string &expression, Method method) {

	//	switch (method) {
	//		case Method::Bisection:
	//		case Method::Chord:
	//		case Method::IterationsWithMaxIterations:
	//		case Method::IterationsWithoutMaxIterations:
	//		case Method::NewtonWithIterations:
	//		case Method::NewtonWithoutIterations:
	//		default:
	//			throw std::invalid_argument("Incorrent method");
	//	}
//	switch (method) {
//		case Method::Bisection: {
//			std::cout << "Solving the equation by bisection method " << expression << " = 0" << std::endl;
//			std::cout << "Type the left and right edge" << std::endl;
//			double left, right;
//			double answer;
//			std::cin >> left; // a
//			std::cin >> right; // b
//			return new BisectionSolver(expression, left, right);
//		}
//		case Method::Chord: {
//			std::cout << "Solving the equation by hip method " << expression << " = 0" << std::endl;
//			std::cout << "Type the left and right edge" << std::endl;
//			double left, right;
//			std::cin >> left; // a
//			std::cin >> right; // b
//			return new ChordSolver(expression, left, right);
//		}
//		case Method::IterationsWithMaxIterations:
//		case Method::IterationsWithoutMaxIterations: { // iteration method
//			std::cout << "Solving the equation by iteration method " << expression << " = 0" << std::endl;
//			double x0, eps;
//			double answer;
//			int n;
//			std::string s;
//			std::cout << "Type start value, eps, function s(x), max amount iteration(or 0):" << std::endl;
//			std::cin >> x0; // x0
//			std::cin >> eps; // error
//			std::cin >> s; // s(x)
//			std::cin >> n; // max iteration count
//			//				x0 = -2;
//			//				eps = 0.0001;
//			//				s = "e^(-x)";
//			//				n = 220;
//			//				if (n)
//			//					answer = iterationWithMaxIterations(x0, eps, n, s); // root
//			//				else
//			//					answer = iterationWithoutMaxIterations(x0, eps, s); // root
//			std::cout << "By iteration method the root is " << answer << std::endl;
//			break;
//		}
//		case 4: { // Newton's method
//			std::cout << "Solving the equation by Newton's method " << expression_string << " = 0" << std::endl;
//			double x0, eps;
//			int n;
//			double answer;
//			std::cout << "Type start value, eps, max amount iteration(or 0)" << std::endl;
//			std::cin >> x0; // x0
//			std::cin >> eps; // error
//			std::cin >> n; // max itetation count
//			//				x0 = 0;
//			//				eps = 0.001;
//			//				n = 0;
//			//				if (n)
//			//					answer = newtonWithIteration(x0, eps, n); // root
//			//				else
//			//					answer = newtonWithoutIteration(x0, eps); // root
//			std::cout << "By Newton's method the root is " << answer << std::endl;
//			//				std::cout << "Net root " << FindRoot(f, x0, 2000) << std::endl;
//			break;
//		}
//
//		default: // didn't match
//			throw std::invalid_argument("Incorrent method");
//	}

	return nullptr;
}

