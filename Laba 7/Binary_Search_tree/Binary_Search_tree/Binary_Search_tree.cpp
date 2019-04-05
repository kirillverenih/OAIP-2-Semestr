

#include "pch.h"
#include <iostream>
#include "Source.h"
#include <random>

using namespace std;
int main()
{
	binary_tree a;
	a.add(25 , "25" , 25);
	a.add(17 , "17" , 17);
	a.add(13 , "13" , 13);
	a.add(11 , "11" , 11);
	a.add(14 , "14" , 14);
	a.add(21 , "21" , 21);
	a.add(43 , "43" , 43);
	a.add(12 , "12" , 12);
	a.add(15 , "15" , 15);
	a.add(16 , "16" , 16);
	a.add(26 , "26" , 26);
	a.add(20 , "20" , 20);
	a.add(22 , "22" , 22);
	a.add(27 , "27" , 27);
	cout << endl << endl;
	a.print_straight();
	a.count();


	//cout << endl << endl;





}
