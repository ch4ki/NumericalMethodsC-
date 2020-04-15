#include "FibonacciMethod.h"
#include <iostream>
#include <math.h>


FibonacciMethod::FibonacciMethod(double (*objective)(double), double initial_point, double final_point, int n) {
	function = objective;
	interval[0] = initial_point;
	interval[1] = final_point;
	step = n;
	fibonacci = new long[n];
	fibonacci_find();
	run();
	delete[] fibonacci;
}
void FibonacciMethod::fibonacci_find() {
	fibonacci = new long[step];
	fibonacci[0] = 1;
	fibonacci[1] = 1;
	for (int i = 2; i < step; i++)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

}

void FibonacciMethod::run() {
	double x1, x2, f1, f2;
	double L_2 = (fibonacci[step - 3] / (double)fibonacci[step - 1]) * (interval[1] - interval[0]);

	std::cout << L_2 << std::endl;
	std::cout << (interval[1] - interval[0]) << std::endl;
	for (int j = 2; j < step; j++)
	{
		L_0 = interval[1] - interval[0];
		x1 = interval[0] + L_2;
		x2 = interval[1] - L_2;
		f1 = function(x1);
		f2 = function(x2);
		if (f1 > f2)
		{
			interval[0] = x1;
			L_2 = (fibonacci[step - j - 1] / (double)fibonacci[step - 1 - (j - 2)]) * (interval[1] - interval[0]);

		}
		else if (f2 > f1)
		{
			interval[1] = x2;
			L_2 = (fibonacci[step - 1 - j] / (double)fibonacci[step - 1 - (j - 2)]) * (interval[1] - interval[0]);
		}
		else {
			interval[0] = x1;
			interval[1] = x2;
			L_2 = (fibonacci[step - 1 - j] / (double)fibonacci[step - 1 - (j - 2)]) * (interval[1] - interval[0]);
			j++;
		}
	}
	double  optimal = (interval[1] + interval[0]) / 2;

	std::cout << "Optimal point lies on x: " << optimal << " f(x): " << function(optimal) << std::endl;
}