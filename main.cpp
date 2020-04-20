#include <iostream>
#include <vector>
#include "shubert_piyavski.h"
double function(double x) {
	return 2 + x + sin(2*x);
};
int main(void) {
	/*std::vector<double> x = { 0,2 };
	Fzeros test([](double x) {return x * (x - 1.5); },x,0.001);
	test.secant(2,5);*/
	//std::tuple<double, double> test0(1,2);
	//std::tuple<double, double> test1(2,1);
	//std::tuple<double, double> test2(4,5);
	//std::vector<std::tuple<double, double>> a{test0,test1,test2};
	//std::vector<double> x = { 0,2 };
	//Fzeros test([](double x) {return x * (x - 1.5); }, x, 0.001);

	


	shubert_piyavskii(function,1,6,3,0.001);	
	/*
	std::vector<double> x = {-4, 4/3.0 };

	Fzeros test([](double x) {return ( (x + 3) * pow((x - 1),2)  ); }, x, 0.001);
	test.BrentMethod();*/
	return 0;
}