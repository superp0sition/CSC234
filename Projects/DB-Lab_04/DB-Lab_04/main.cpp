#include<iostream>
#include "Cylinder.h"
using namespace std;

int main()
{
	Cylinder Cylinder1(5.0, 10.0); //radius = 5.0 and height = 10.0
	Cylinder Cylinder2(3.5, 20.0); //radius = 3.5 and height 20.0
	Cylinder Cylinder3;
	Cylinder Cylinder4;
	Cylinder Cylinder5;

	cout << "Cylinder1 --- " << Cylinder1 << endl;
	cout << "Cylinder2 --- " << Cylinder2 << endl;

	Cylinder3 = Cylinder1 + Cylinder2;
	cout << "Cylinder1 + Cylinder2 = " << "Cylinder3 --- " << Cylinder3 << endl;

	Cylinder4 = Cylinder1 - Cylinder2;
	cout << "Cylinder1 - Cylinder2 = " << "Cylinder4 --- " << Cylinder4 << endl;

	Cylinder5 = Cylinder1 * Cylinder2;
	cout << "Cylinder1 * Cylinder2 = " << "Cylinder5 --- " << Cylinder5 << endl;

	cout << "Compare Cylinder1 > Cylinder2 --- " << endl;
	if (Cylinder1 > Cylinder2)
		cout << "Cylinder1 is greater than Cylinder2." << endl;
	else
		cout << "Cylinder1 is less than or equal to Cylinder2." << endl << endl;

	Cylinder1++;
	cout << "Cylinder1++ --- " << endl;
	cout << "New dimension of Cylinder1: " << Cylinder1 << endl;

	Cylinder4 = Cylinder3++;
	cout << "Cylinder4 = Cylinder3++ --- " << endl;
	cout << "New dimension of Cylinder3: " << Cylinder3 << endl;
	cout << "New dimension of Cylinder4: " << Cylinder4 << endl;

	cout << "Cylinder4 != Cylinder3 --- Cylinder4 is "
		<< (Cylinder4 != Cylinder3 ? "not equal to Cylinder3 " : "equal to Cylinder3") << endl;
	cout << "Cylinder4 >= Cylinder3 --- Cylinder4 is "
		<< (Cylinder4 >= Cylinder3 ? "greater or equal to Cylinder3 " : "less than Cylinder3 ") << endl;
	cout << "Cylinder4 == Cylinder3 --- Cylinder4 is "
		<< (Cylinder4 == Cylinder3 ? "equal to Cylinder3 " : "not equal to Cylinder3") << endl;
	cout << "Cylinder4 < Cylinder3 --- Cylinder4 is "
		<< (Cylinder4 < Cylinder3 ? "less than Cylinder3 " : "greater than or equal to Cylinder3") << endl;
	cout << "Cylinder4 <= Cylinder3 --- Cylinder4 is "
		<< (Cylinder4 <= Cylinder3 ? "less than or equal to Cylinder3 " : "greater than Cylinder3") << endl;
	return 0;
}
