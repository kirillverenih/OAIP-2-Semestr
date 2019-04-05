
#include "pch.h"
#include <iostream>
#include "Source.cpp"

using  namespace std;

int main()
{
	queue <int> a;
	a.push(19);
	a.push(12);
	a.push(11);
	a.push(16);
	a.push(24);
	a.sort_by_value();
	a.Task();

	cout << a.see() << endl;
	a.pop_front();
	cout << a.see() << endl;
	a.pop_front();

	cout << "Size "<< a.get_size() << endl;
	cout << "Is empty " << a.isempty() << endl;
	system("pause");
}
