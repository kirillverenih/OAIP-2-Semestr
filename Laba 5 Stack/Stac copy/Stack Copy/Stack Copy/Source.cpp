#include <iostream>
#include <string>
#include "Stak.cpp"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	MyStack <int> a;
	cout << "//���������� ��������� \n";
	a.push(2);
	a.push(3);
	a.push(10);
	a.push(4);

	a.pop();
	a.DisplayAll();

	cout << "//���������� ��������\n";
	a.push(2);
	a.push(3);
	a.push(10);
	a.push(15);
	a.push(4);
	a.push(1);
	a.push(99);

	a.sort_by_value();
	a.DisplayAll();

	cout << "//���������� ���������\n";
	a.push(2);
	a.push(3);
	a.push(10);
	a.push(15);
	a.push(4);
	a.push(1);
	a.push(99);

	a.sort_by_adress();
	a.DisplayAll();

	cout << "//��� �������\n";
	a.push(2);
	a.push(4);
	a.push(3);
	a.push(10);
	a.push(15);
	a.push(4);
	a.push(99);
	a.push(2);


	a.Task();
	a.DisplayAll();

	system("pause");
}
