#ifndef SHUBERT_H
#define SHUBERT_H
#include <vector>

class Point {
public:
	double x, y;
	Point(double x, double y);
	
};

Point* GetSpIntersection(Point A, Point B, double L);

void shubert_piyavskii(double (*f)(double), double a, double b, double l, double epsilon, double sigma=0.01);
int Argmin(std::vector<Point*> a);

#endif