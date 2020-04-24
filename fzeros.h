#pragma once
#ifndef FZEROS_H_
#define FZEROS_H_
#include <vector>

class Fzeros
{
public:
	double (*function)(double);
	std::vector<double> boundries;
	std::vector<double> mullerPoly;
	std::vector<double> optimum;
	double relativity = 10E-13;
	Fzeros(double (*x)(double));
	std::vector<double> bisection();
	std::vector<double> secant(double starting_point, int iteration, double sigma = 0.01);
	double secant(double a, double b);
	/*std::vector<std::tuple<double, double>> points*/
	double InverseQuadraticInterpolation(double x_0, double y_0, double x_1, double y_1, double x_2, double y_2);
	void BrentMethod();
	std::vector<double> Muller(double x0, double x1, double x2, double tolerance = 10E-9);
	void SyntheticDivision(std::vector<double> polynomial, double constant);
	double Function(double x);
};
template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
};

#endif