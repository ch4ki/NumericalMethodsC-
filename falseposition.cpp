#include "falseposition.h"
#include <iostream>



FalsePosition::FalsePosition(double(*x)(double), double l_boundry, double u_boundry, double relativity):
relativity(relativity) {
	function = x;
	array[0] = l_boundry;
	array[1] = u_boundry;
	start();
};

void FalsePosition::start() {
	do {

		double temp = r;
		r = array[1] - (function(array[1])(array[0] - array[1])) / (function(array[0]) - function(array[1]));
		error = abs((r - temp) / temp);
		if (function(r) == 0)
		{
			std::cout << r << " is exact root have been founded" << std::endl;
			break;
		}
		else if (function(r) * function(array[0]) < 0) {
			array[1] = r;
		}
		else if (function(r) * function(array[1]) < 0) {
			array[0] = r;
		}
		std::cout << "Precisely root is: " << r << " function(r): " << function(r) <<
			" Relative error is: " << error
			<< std::endl;

	} while (true);//error > relativity);
	optimum_points[0] = r;
	optimum_points[1] = function(r);
	std::cout << "Optimal x: " << optimum_points[0] << " and function(x): " << optimum_points[1] << std::endl;

}
