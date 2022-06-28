#include "account.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	std::string name;
	int id = 1;

	cout << "Enter customer name: ";
	//cin.ignore(100, '\n'); // wasn't sure if this would be necessary at first 
	getline(cin, name); // get the line after the prompt

	auto a = new account(1, name.c_str(), 0.00);

	a->display_account();

	try
	{
		double amount;
		cout << "How much to deposit? "; cin >> amount;
		a->deposit(amount);

		a->display_account();

		cout << "How much to withdraw? "; cin >> amount;
		a->withdraw(amount);

		a->display_account();
	}
	catch (accountException& e) // re-sharper caught a mistake here for me, originally didn't have address of the exception 
	{
		cout << e.what() << endl;
	}

	// Is there something I could add to these labs to make them slightly more challenging?
	// I really enjoy this stuff, but feel like I'm not doing much thinking, is there something
	// that I could do to make them a bit more difficult?
}