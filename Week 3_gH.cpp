//extra shipping cost if fragile = $2.00(add to shipping cost)
//no magic number and hard coding
//order total		ship(USA)		Ship(CAN)		ship(AUS)		ship(mars)
//less than 50			6				8				10				15
//50 to 100				9				12				14				20
//100 to 150			12				15				17				25
//over 150				free			free			free			free
//program needs to write in console window and in a file named Order.txt


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

const double fcost = 2.00;			// shipping cost extra $2.00 if fragile

const string output = "Order.txt";	// to show output in order.txt file along with console window

const int dot1 = 50;
const int dot2 = 14;
const int dot3 = 19;
const int dota = 23;			// also these all are number needed to print the dot and dash in the code
const int dot4 = 8;			// these numbers do not change 
const int dot5 = 20;			// these had to be done to avoid magic numbers
const int dot6 = 24;
const int dot7 = 12;
const int dot = 27;

int main()
{
	string name;
	string fragile;
	double order;
	string destn;

	ofstream ofile;
	ofile.open(output);

	if (!ofile)
	{
		cout << "error opening outputfile";		// in case order.txt doesn't open
		return 2;
	}

	cout << setfill('.');		// to fill the gap with .
	ofile << setfill('.') << '.' << setw(dot1) << '.' << endl;
	cout << '.' << setw(dot1) << '.' << endl;

	cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
	ofile << "ITCS 2530 - Programming Assignment for week #3" << endl;

	cout << '.' << setw(dot1) << '.' << endl << endl << endl;
	ofile << '.' << setw(dot1) << '.' << endl << endl << endl;

	cout << "Please enter the item name (no spaces)" << setw(dot2) << ":";
	cin >> name;
	ofile << "Please enter the item name (no spaces)" << setw(dot2) << ":" << name << endl;

	cout << "Is the item fragile? (y=yes/n=no)" << setw(dot3) << ":";
	cin >> fragile;
	ofile << "Is the item fragile? (y=yes/n=no)" << setw(dot3) << ":" << fragile << endl;
	transform(fragile.begin(), fragile.end(), fragile.begin(), toupper);

	// this is to make all input for fragile uppercase. 
	// As a result, we don't have to worry about the case: y and n, 

	bool truth = (fragile == "Y");		// already y and n are changed to Y and N
	bool truth1 = (fragile == "N");
	if (!truth && !truth1)
	{
		// in case user input anything other than y and n

		cout << endl << "Invalid entry, exiting";
		ofile << endl << "Invalid entry, exiting";
		return 0;
	}

	cout << "Please enter your order total" << setw(dota) << ":";
	cin >> order;
	ofile << "Please enter your order total" << setw(dota) << ":" << order << endl;

	cout << "Please enter destination. (usa/can/aus/mars)" << setw(dot4) << ":";
	cin >> destn;
	ofile << "Please enter destination. (usa/can/aus/mars)" << setw(dot4) << ":" << destn << endl;
	transform(destn.begin(), destn.end(), destn.begin(), toupper);

	// in the output, we have to show the destination in uppercase.

	bool truth2 = (destn == "USA");
	bool truth3 = (destn == "CAN");		// using manipulators to convert them into boolean 
	bool truth4 = (destn == "AUS");
	bool truth5 = (destn == "MARS");
	if (!truth2 && !truth3 && !truth4 && !truth5)
	{
		// if user gives any wrong input 
		cout << endl << "Invalid entry, exiting";
		ofile << endl << "Invalid entry, exiting";
		return 1;
	}


	double cost = 0.00;
	double cost1usa = 6.00;
	double cost1can = 8.00;
	double cost1aus = 10.00;
	double cost1mars = 15.00;
	double cost2usa = 9.00;
	double cost2can = 12.00;
	double cost2aus = 14.00;
	double cost2mars = 20.00;
	double cost3usa = 12.00;
	double cost3can = 15.00;
	double cost3aus = 17.00;
	double cost3mars = 25.00;

	// these are all shipping cost for different locations and different order price range

	if (order > 0.00 && order <= 50)		// order price range
	{
		if (truth2)		// shipping to usa
		{
			if (truth)		// for fragile items
			{
				cost = cost1usa + fcost;		// adds $2.00
			}
			else
			{
				cost = cost1usa;		// shipping cost doesn't change, if not fragile
			}
		}
		if (truth3)		// shipping to canada
		{
			if (truth)
			{
				cost = cost1can + fcost;
			}
			else
			{
				cost = cost1can;
			}
		}
		if (truth4)		// shipping to australia
		{
			if (truth)
			{
				cost = cost1aus + fcost;
			}
			else
			{
				cost = cost1aus;
			}
		}
		if (truth5)		// shipping to mars
		{
			if (truth)
			{
				cost = cost1mars + fcost;
			}
			else
			{
				cost = cost1mars;
			}
		}
	}

	if (order >= 50.01 && order <= 100.00)			// 2nd order range
	{
		if (truth2)
		{
			if (truth)
			{
				cost = cost2usa + fcost;
			}
			else
			{
				cost = cost2usa;
			}
		}
		if (truth3)
		{
			if (truth)
			{
				cost = cost2can + fcost;
			}
			else
			{
				cost = cost2can;
			}
		}
		if (truth4)
		{
			if (truth)
			{
				cost = cost2aus + fcost;
			}
			else
			{
				cost = cost2aus;
			}
		}
		if (truth5)		// shipping to mars
		{
			if (truth)
			{
				cost = cost2mars + fcost;
			}
			else
			{
				cost = cost2mars;
			}
		}
	}

	if (order >= 100.01 && order <= 150.00)		// 3rd order range
	{
		if (truth2)
		{
			if (truth)
			{
				cost = cost3usa + fcost;
			}
			else
			{
				cost = cost3usa;
			}
		}
		if (truth3)
		{
			if (truth)
			{
				cost = cost3can + fcost;
			}
			else
			{
				cost = cost3can;
			}
		}
		if (truth4)
		{
			if (truth)
			{
				cost = cost3aus + fcost;
			}
			else
			{
				cost = cost3aus;
			}
		}
		if (truth5)		// shipping to mars
		{
			if (truth)
			{
				cost = cost3mars + fcost;
			}
			else
			{
				cost = cost3mars;
			}
		}
	}

	if (order > 150.00)			// 4th order range
	{
		if (truth2 || truth3 || truth4 || truth5)
		{
			cost = cost;		// anything over 150 cost does not change
		}
	}

	cout << fixed << setprecision(2);		// to show two decimal points always
	cout << endl << "Your item is";

	ofile << fixed << setprecision(2);
	ofile << endl << "Your item is";

	int a = 0;
	while (a <= dot)
	{
		cout << '.';
		ofile << '.';
		a++;
	}
	cout << name << endl;
	ofile << name << endl;

	cout << "Your shipping cost is" << setw(dot5) << "$" << cost << endl;
	ofile << "Your shipping cost is" << setw(dot5) << "$" << cost << endl;

	cout << "You are shipping to" << setw(dot6) << destn << endl;
	ofile << "You are shipping to" << setw(dot6) << destn << endl;

	order = order + cost;		// total order cost(order total+ shipping cost) 

	cout << "Your total shipping costs are" << setw(dot7) << "$" << order << endl << endl;
	ofile << "Your total shipping costs are" << setw(dot7) << "$" << order << endl << endl;

	cout << setfill('-') << setw(dot1) << "Thank you!" << endl;
	ofile << setfill('-') << setw(dot1) << "Thank you!" << endl;

	ofile.close();
}