#include "pch.h"
#include <iostream>
#include <string>
#include <locale.h>
#include "Source.cpp"

using namespace std;

int main() {
	setlocale(0 ,"russian");
	stack <int> a;

	cout << "Добовление элементов в стак \n";
	a.push(33);
	a.push(25);
	a.push(97);
	a.push(13);

	cout << "size of stack: " << a.get_size() << endl << endl << endl;
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	cout << endl << endl;

	system("pause");
	cout << "Сортировка по значению\n";
	a.push(33);
	a.push(25);
	a.push(13);
	a.push(97);
	a.sort_by_value();

	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl << endl;
	a.pop();

	system("pause");
	cout << "Сортировка по адрессу \n";
	a.push(33);
	a.push(25);
	a.push(13);
	a.push(97);
	a.sort_by_adress();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl << endl << endl;
	a.pop();

	system("pause");
	cout << "Мое задание (Ужадение всех четный чисел)\n";
	a.push(10);
	a.push(20);
	a.push(13);
	a.push(17);
	a.push(16);
	a.push(99);
	a.push(100);
	a.push(77);
	a.sort_by_adress();

	cout << "До удаления \n";
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	
//================//
	a.push(10);
	a.push(20);
	a.push(13);
	a.push(17);
	a.push(16);
	a.push(99);
	a.push(100);
	a.push(77);
	a.sort_by_value();
	a.Task();

	cout << "После удаления \n";
	a.sort_by_adress();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();
	cout << a.see() << endl;
	a.pop();


}
