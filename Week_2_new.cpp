//A cheese container can hold 2.76 kg of cheese. 
//Each evening, a fromager ships containers of cheese to a local grocery store. 
//The cost of producing one container of cheese is $4.12, 
//and the profit of each container of cheese is $1.45.

#include <iostream>
#include<string>
#include<iomanip>		// header for parametic manipulation

using namespace std;

const string asterisk = "*";
const double cheese = 2.76;
const double cost = 4.12;
const double profit = 1.45;

int main()
{
	int a = 0;
	while (a <= 79)
	{
		cout << asterisk;
		a = a + 1;
	}
	cout << endl;
	a = 0;
	while (a <= 15)
	{
		cout << asterisk;
		a = a + 1;
	}
	cout << " Cheese business time ";
	a = 0;
	while (a <= 33)
	{
		cout << asterisk;
		a = a + 1;
	}
	cout << endl;
	a = 0;
	while (a <= 79)
	{
		cout << asterisk;
		a = a + 1;
	}

	///////
	// code to find container number, cost and profit starting from here

	cout << endl << "Please enter the total number of kilograms of cheese produced: ";

	double Cheesekg = 0;		// cheese can be decimal; that's why double
	int container = 0;			// container is integer always. There is nothing like a half container
	double Totalcost = 0;		// cost can be decimal
	double TotalProfit = 0;		// profit can be decimal too

	cin >> Cheesekg;

	container = Cheesekg / cheese;		// 1 container can hold 2.76 kg cheese; so, by dividing the total cheese with it will give the container number
	if (container * cheese < Cheesekg)
	{
		container = (Cheesekg / cheese) + 1;	// there is a case where there is still a bit cheese left, but it will not fill the container
	}										// but you still need a container
	else
	{
		container = (Cheesekg / cheese);		// when no more cheese is left
	}

	cout << "The number of containers to hold the cheese is : " << setw(34) << container << endl;

	// setw is used to present them all in the same line

	Totalcost = cost * container;
	cout << "The cost of producing " << to_string(container) << " container(s) of cheese is: $" << setw(29) <<  Totalcost << endl;

	TotalProfit = profit * container;
	cout << "The profit from producing " << to_string(container) << " container(s) of cheese is: $" << setw(24) << TotalProfit << endl;

	return 0;
}

