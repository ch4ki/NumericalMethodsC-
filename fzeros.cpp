#include <iostream>
#include <tuple>
#include "fzeros.h"
Fzeros::Fzeros(double (*x)(double)) {
	
	function = x;
};

std::vector<double> Fzeros::bisection() {
	double r = 2;
	double error;
	do {
		double temp = r;
		r = (boundries[0] + boundries[1]) / 2;
		error = abs((r - temp) / temp);
		if (function(r) == 0)
		{
			std::cout << r << " is exact root have been founded" << std::endl;
			break;
		}
		else if (function(r) * function(boundries[0]) < 0) {
			boundries[1] = r;
		}
		else if (function(r) * function(boundries[1]) < 0) {
			boundries[0] = r;
		}

	} while (true);
	optimum.push_back(r);
	optimum.push_back(function(r));
	std::cout << "Optimal x: " << optimum[0] << " and function(x): " << optimum[1] << std::endl;
	return optimum;
}

std::vector<double> Fzeros::secant(double starting_point, int iteration, double sigma) {

	double error;
	double x0 = starting_point - sigma, x1 = starting_point, x;
	do {
		x = x1 - function(x1) * (x1 - x0) / (function(x1) - function(x0));
		error = abs((x - x1) / x1);
		x0 = x1;
		x1 = x;

	} while (error >= relativity);
	optimum.push_back(x);
	std::cout << x << "and function(x): " << function(x) << std::endl;
	optimum.push_back(function(x));
	return optimum;
};
double Fzeros::secant(double a, double b) {
	std::cout << "Secant method in" << std::endl;
	double s = b - (function(b) * (b - a)) / (function(b) - function(a));
	return s;

}
/*std::vector<std::tuple<double, double>> points*/
double Fzeros::InverseQuadraticInterpolation(double x_0, double y_0, double x_1, double y_1, double x_2, double y_2) {
	std::cout << "Inverse method in" << std::endl;
	double x_i, f_i;
	double a, b, c;
	a = (y_1 * y_2 * x_0) / ((y_0 - y_1) * (y_0 - y_2));

	b = (y_0 * y_2 * x_1) / ((y_1 - y_0) * (y_1 - y_2));

	c = (y_0 * y_1 * x_2) / ((y_2 - y_0) * (y_2 - y_1));

	x_i = a + b + c;
	f_i = function(x_i);
	return x_i;
};
void Fzeros::BrentMethod() {
	double a = boundries[0];
	double b = boundries[1];
	double c, s, d;
	if (function(boundries[0]) * function(boundries[1]) >= 0) {
		std::cout << "Root is not bracketed exiting..";
		return;
	}
	if (abs(function(a)) < abs(function(b))) {
		std::swap(a, b);
	}
	c = a; s = b;
	bool flag = true;
	do
	{
		if ((function(a) != function(c)) || (function(b) != function(c)))
		{
			//Inverse quadratic interpolation
			s = InverseQuadraticInterpolation(a, function(a), b, function(b), c, function(c));
		}
		else {
			s = secant(a, b);
		}

		if (
			(a * 3 + b <= s || s <= b) && (3 * a + b >= s || s >= b) &&
			flag || abs(s - b) >= abs(b - c) / 2 &&
			!flag || abs(s - b) >= abs(c - d) / 2 &&
			flag || abs(b - c) < abs(relativity) &&
			flag || abs(c-d) < abs(relativity)	)
		{
			s = (a + b) / 2;
			flag = true;
		}
		else {
			flag = false;
		}
		d = c;
		c = b;
		if (function(a) * function(s) < 0) {
			b = s;
		}
		else {
			a = s;
		}
		if (abs(function(a)) < abs(function(b)))
		{
			std::swap(a, b);
		}
	} while (function(b) != 0 && function(s) != 0 && abs(b - a) < relativity);

	std::cout << b;
}


double Fzeros::Function(double x) {
	double result = 0;
	int n = mullerPoly.size();
	for (int i = 0; i < n; i++)
	{
		result += mullerPoly[i] * pow(x, (n - 1) - i);
	}

	return result;
}
void Fzeros::SyntheticDivision(std::vector<double> polynomial, double constant) {
	int n = polynomial.size();
	std::vector<double> quotient(n - 1);
	quotient[0] = polynomial[0];
	for (int i = 1; i < quotient.size(); i++)
	{
		quotient[i] = quotient[i - 1] * constant + polynomial[i];
	}

	mullerPoly = quotient;
}
std::vector<double> zeros;
std::vector<double> Fzeros::Muller(double x0, double x1, double x2, double tolerance)
{
	// You should solve complex problem okay?

	double h0, h1, d0, d1, a, b, c, D, x, x3, eps;

	int iteration = 0;
	do
	{

		h0 = x1 - x0;
		h1 = x2 - x1;
		d0 = (Function(x1) - Function(x0)) / (x1 - x0);
		d1 = (Function(x2) - Function(x1)) / (x2 - x1);
		a = (d1 - d0) / (h1 + h0);
		b = a * h1 + d1;
		c = Function(x2);
		D = sqrt(pow(b, 2) - 4 * a * c);
		if (D == D) {
			x3 = x2 + (-2 * c) / (sgn(b) * (abs(b) + D));
			eps = abs((x3 - x2) / x3) * 100;
		}
		else {

			//throw("WARNING: Discriminant is negative");
			return zeros;
		}
		if (abs(Function(x3)) < tolerance) {
			x = x3;
			zeros.push_back(x);
			std::cout << "Optimal point has been found x=" << x << " f(x):" << Function(x) << " relative error: " << eps << std::endl;
			SyntheticDivision(mullerPoly, x);
			if (mullerPoly.size() != 2) {
				Muller(a, b, c);
			}
			else {
				zeros.push_back(-1 * mullerPoly[1]);
				return zeros;
			}

		}
		iteration++;
		if (x3 < x0) {
			x2 = x1; x1 = x0; x0 = x3;
		}
		else if (x3 < x1)
		{
			x2 = x1; x1 = x3;
		}
		else if (x3 < x2)
		{
			x0 = x1; x1 = x3;
		}
		else {
			x0 = x1; x1 = x2; x2 = x3;
		}
		std::cout << "Iteration: " << iteration << " found x=" << x3 << " f(x):" << Function(x3) << " relative error: " << eps << std::endl;

	} while (true);
}