#include "shubert_piyavski.h"
#include <memory>
#include<iostream>
#include <list> 

using namespace std;
Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
};
Point* GetSpIntersection(Point *A, Point *B, double l) {
	double t = ((A->y - B->y) - l * (A->x - B->x)) / (2 * l);
	cout << t << endl;
	Point *a = new Point(A->x + t, A->y - l * t);
	return  a;
};

int Argmin(std::vector<Point*> a)
{
	double min = 10E10;
	int index = -1;

	for (int i = 0; i < a.size(); ++i) {

		if (a[i]->y < min) {
			min = a[i]->y;
			index = i;
		}
	}
	if (index < 0) {
		throw "Argmin is negative";
	}
	else {
		return index;
	}
	return 0;
}
void shubert_piyavskii(double (*f)(double), double a, double b, double l, double epsilon, double sigma) {

	double m = (a + b) / 2;
	Point *A = new Point(a, f(a));
	Point *B = new Point(b, f(b));
	Point *M = new Point(m, f(m));
	vector<Point*> pts{A,GetSpIntersection(A,B,l) ,M,GetSpIntersection(M,B,l),B};
	double tolerance = 10E10;

	int i = -1;
	int k = 0;
	while (tolerance > epsilon)
	{
		k++;
		i = Argmin(pts);
		Point* P = new Point(pts[i]->x, f(pts[i]->x));
		cout << P->y << endl;
		cout << pts[i]->y << endl;
		tolerance = P->y - pts[i]->y;
		Point* P_prev = GetSpIntersection(pts[i - 1], P, l);
		Point* P_next = GetSpIntersection(P, pts[i + 1], l);

		pts.erase(pts.begin() + i);
		pts.insert(pts.begin() + i, P_next);
		pts.insert(pts.begin() + i, P);
		pts.insert(pts.begin() + i, P_prev);

	}
	

	cout <<"x is: " <<pts[i]->x << " It's minimum value at f(x): " << f(pts[i]->x) << "Iteration count: " << k << endl;
	for (int j = 0; j < size(pts); j++)
	{
	
		delete pts[j];
	}
	

};

