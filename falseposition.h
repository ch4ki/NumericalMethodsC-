#pragma once
class FalsePosition {
private:
	double array[2];
	double r = 2;
	double error;
	double relativity;
	double (*function)(double);

public:
	FalsePosition(double (*x)(double), double l_boundry, double u_boundry, double relativity = 0.0000000001);
	void start();
	double optimum_points[2];
	//double function(double x);
};
