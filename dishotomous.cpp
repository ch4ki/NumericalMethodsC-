#include "dishotomous.h"
#include <math.h>
#include <iostream>

Dishotomous::Dishotomous(double(*x)(double), double x_left, double x_right, double accuracy) :
	accuracy(accuracy)
{
	interval[1] = x_right;
	interval[0] = x_left;
	function = x;
	L_0 = (interval[1] + interval[0]);
	step_find();
	run();
};

void Dishotomous::step_find() {
	int temp = ceil(-2 * log2((2 * accuracy * (interval[1] - interval[0]) - sigma) / ((interval[1] - interval[0]) - sigma)));
	step = (temp % 2 == 1) ? (temp + 1) : temp;
};

void Dishotomous::run() {
	sigma = sigma / 2;
	for (int i = 0; i < step / 2; i++)
	{
		double x1 = L_0 / 2 - sigma;
		double x2 = L_0 / 2 + sigma;
		double f1 = function(x1);
		double f2 = function(x2);
		(f1 > f2) ? interval[0] = x1 : interval[1] = x2;
		L_0 = (interval[1] + interval[0]);
	}
	optimum[0] = L_0 / 2;
	optimum[1] = function(L_0);
	std::cout << "Optimization is done: Optimum points are: x = " << optimum[0] << " f(x): " << function(optimum[0]) << std::endl;
};
double Dishotomous::getStep() {
	std::cout << step;
	return step;
}