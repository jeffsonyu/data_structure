/**
 * @file LListMain.cpp
 * @brief Test case for Singly-linked list
 * 
 */

#include "LList.h"
#include <iostream>

using namespace std;

int main()
{
	int a = 0;
	DList<int> aL(50);
	aL.insert(3);
	aL.print();
	aL.insert(1);
	aL.print();
	aL.insert(4);
	aL.print();
	aL.insert(1);
	aL.print();
	aL.insert(5);
	aL.print();
	aL.insert(9);
	aL.print();
	aL.insert(2);
	aL.print();
	aL.insert(6);
	aL.print();
	aL.setPos(3);
	aL.print();
	aL.remove(a);
	aL.print();
	cout << "The number just removed is " << a << endl;

	aL.clear();
	aL.append(3);
	aL.print();
	aL.append(1);
	aL.print();
	aL.append(4);
	aL.print();
	aL.append(1);
	aL.print();
	aL.append(5);
	aL.print();
	aL.append(9);
	aL.print();
	aL.append(2);
	aL.print();
	aL.append(6);
	aL.print();
	aL.setPos(3);
	aL.print();
	aL.remove(a);
	aL.print();
	cout << "The number just removed is " << a << endl;
	aL.setPos(3);
	aL.setPos(7);
	aL.remove(a);
	aL.setPos(6);
	aL.remove(a);


	return 0;
}
