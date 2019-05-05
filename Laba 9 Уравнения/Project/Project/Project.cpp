#include "pch.h"
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double
func(double x)
{
	return (pow(x, 2) - 10 * pow(sin(x), 2) + 2);
}; // main func


double find(double start, double end, double step)
{
	double x = end, f0, f;
	cout << "Start: " << start << " End: " << end << " ";
	do {
		f = func(x);						//find y(end of interval)
		f0 = func(start);					//find y(begin of interval)
		x = x - f / (f - f0) * (x - start);	//formula
	} while (fabs(f) > step);				//rounding 
	return x;
}

struct element
{
	double begin, end;
	element(double b, double c)
	{
		this->begin = b;
		this->end = c;
	};
};


vector<element> funcone(double a, double b, double step)
{
	vector<element> vec;
	for (double x = a; x <= b; x += step)
	{
		if (func(x) * func(x + step) < 0)
		{
			vec.push_back(element(x, x + step));
		}
		else
		{
			continue;
		}
	}
	return vec;
}

int main()
{
	double a, b, step, step2;
	cout << "Input a(interval begin): ";
	cin >> a;
	cout << "Input b(interval end): ";
	cin >> b;
	cout << "Input step: ";
	cin >> step;
	cout << "Input step for solution: " << endl;
	cin >> step2;
	vector<element> interval = funcone(a, b, step);
	cout << "\n";
	if (interval.size() != 0)
	{
		cout << "Function: sqrt(x)+(cos(X)^2)-2 has:"
			<< "\n\n";
		for (size_t i = 0; i < interval.size(); i++)
		{
			cout << "Root in range from " << interval[i].begin << " to "
				<< interval[i].end << "\n";
		}
		cout << "\n\n";
	}
	else
	{
		cout << "No roots found"
			<< "\n\n";
	}
	for (size_t i = 0; i < interval.size(); i++)
	{
		double print = find(interval[i].begin, interval[i].end, step2);
		cout << endl;
		cout << "root " << i + 1 << " : " << print << "\n";
		cout << "Function in root = " << func(print) << "\n\n\n";
	}
	return 0;
}
