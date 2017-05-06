#include "defines.h"
#include "solvingEquation.h"
#include "plottingGraph.h"

//global initialization
string expression_string = "cos(x)-x * e^x";
ParserWithConsts expression;

double f(double x){
	return expression.Eval(&x);
}

double FindRoot(double (*f)(double), double x0, int n){
	double x = x0, df, h = 0.00001;
	df = (f(x + h) - f(x)) / h;
	for (int i = 1; i <= n; i++) {
//		cout <<  x << "!" << endl;
		x = x - f(x) / df;
	}
	return x;
}

int main(int argc, char **argv){
	cout << "Type the function to find its root\ny = ";
	getline(std::cin, expression_string); // our main string function
	string titleWindow = "Plotting graph y(x) = " + expression_string; // title of our window
	expression.Parse(expression_string, "x"); // parse string to function
	cout << "Choose the method for solving equations:" << endl;
	cout << "\t1)Bisection method\n\t2)Hip method\n\t3)Iteration method\n\t4)Newton's method" << endl;
	cout << "Type choosen number" << endl;
	int method = 0;
	cin >> method; // number of choosen method
//	method = 4;
	thread solving([&method]{
		switch (method) {
			case 1: { // bisection
				cout << "Solving the equation by bisection method " << expression_string << " = 0" << endl;
				cout << "Type the left and right edge" << endl;
				double left, right;
				double answer;
				cin >> left; // a
				cin >> right; // b
				answer = bisection(left, right); // root
				cout << "By bisection the root is " << answer << endl;
				break;
			}
			case 2: { // hip method
				cout << "Solving the equation by hip method " << expression_string << " = 0" << endl;
				cout << "Type the left and right edge" << endl;
				double left, right;
				double answer;
				cin >> left; // a
				cin >> right; // b
				answer = hip(left, right); // root
				cout << "By hip method the root is " << answer << endl;
				break;
			}
			case 3: { // iteration method
				cout << "Solving the equation by iteration method " << expression_string << " = 0" << endl;
				double x0, eps;
				double answer;
				int n;
				string s;
				cout << "Type start value, eps, function s(x), max amount iteration(or 0):" << endl;
				cin >> x0; // x0
				cin >> eps; // error
				cin >> s; // s(x)
				cin >> n; // max iteration count
//				x0 = -2;
//				eps = 0.0001;
//				s = "e^(-x)";
//				n = 220;
				if (n)
					answer = iterationWithMaxIterations(x0, eps, n, s); // root
				else
					answer = iterationWithoutMaxIterations(x0, eps, s); // root
				cout << "By iteration method the root is " << answer << endl;
				break;
			}
			case 4: { // Newton's method
				cout << "Solving the equation by Newton's method " << expression_string << " = 0" << endl;
				double x0, eps;
				int n;
				double answer;
				cout << "Type start value, eps, max amount iteration(or 0)" << endl;
				cin >> x0; // x0
				cin >> eps; // error
				cin >> n; // max itetation count
//				x0 = 0;
//				eps = 0.001;
//				n = 0;
				if (n)
					answer = newtonWithIteration(x0, eps, n); // root
				else
					answer = newtonWithoutIteration(x0, eps); // root
				cout << "By Newton's method the root is " << answer << endl;
//				cout << "Net root " << FindRoot(f, x0, 2000) << endl;
				break;
			}
			
			default: // didn't match
				cout << "Error! Wrong number\n";
				break;
			
		}
	});
	solving.detach(); // detaching our extra thread
	
	windowStart(argc, argv, titleWindow.c_str()); // configurating our window with graph
	
	glutMainLoop(); // main loop of our window
	return 0;
}