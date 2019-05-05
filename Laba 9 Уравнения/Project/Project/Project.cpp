#include "pch.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <conio.h>
using namespace std;
double func(double x) { return sqrt(x) - pow((cos(x)), 2) - 2; }; // main func

struct element {
	double begin, end;
	element(double b, double c) {
		this->begin = b;
		this->end = c;
	};
};

vector<element> FindRoots(double a, double b, double step) {
	vector<element> vec;
	for (double x = a; x <= b; x += step) {
		if (func(x) * func(x + step) < 0) {
			vec.push_back(element(x, x + step));
		}
		else {
			continue;
		}
	}
	return vec;
}

double func1(double x, double step, double) { return 0; };

int main(int argc, char const *argv[]) {
	double a, b, step;
	cout << "Input a(interval begin): ";
	cin >> a;
	cout << "Input b(interval end): ";
	cin >> b;
	cout << "Input step: ";
	cin >> step;
	vector<element> interval = FindRoots(a, b, step);
	cout << "\n";
	if (interval.size() != 0) {
		cout << "Function: sqrt(x)+(cos(X)^2)-2 has:"
			<< "\n\n";
		for (size_t i = 0; i < interval.size(); i++) {
			cout << "Root in range from " << interval[i].begin << " to "
				<< interval[i].end << "\n";
		}
		cout << "\n\n";
	}
	else {
		cout << "No roots found("
			<< "\n\n";
	}

	return 0;
}