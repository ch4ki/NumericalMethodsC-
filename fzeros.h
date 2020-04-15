#pragma once
#ifndef FZEROS_H_
#define FZEROS_H_
#include <vector>

class Fzeros
{
public:
	double (*function)(double);
	std::vector<double> boundries;
	std::vector<double> optimum;
	double relativity = 10E-13;
	Fzeros(double (*x)(double), std::vector<double>& interval, double relativity_pa = 0.001);
	std::vector<double> bisection();
	std::vector<double> secant(double starting_point, int iteration, double sigma = 0.01);
	double secant(double a, double b);
	/*std::vector<std::tuple<double, double>> points*/
	double InverseQuadraticInterpolation(double x_0, double y_0, double x_1, double y_1, double x_2, double y_2);
	void BrentMethod();
};


#endif