#pragma once
class Dishotomous
{
private:
	double interval[2];
	double L_0;
	double (*function)(double);
	double accuracy;
	double step;
	double sigma = 0.001;
	double optimum[2];
public:
	Dishotomous(double(*x)(double), double x_left, double x_right, double accuracy = 0.1);
	void step_find();
	void run();
	double getStep();


};
