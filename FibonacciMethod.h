#pragma once
class FibonacciMethod {
private:
	double (*function)(double);
	double interval[2];
	int step;
	long* fibonacci;
	double L_0;
	void fibonacci_find();
public:
	FibonacciMethod(double (*objective)(double), double initial_point, double final_point, int n);
	void run();

};