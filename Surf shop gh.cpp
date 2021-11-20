//Johnny Utah owns a surf shop on the beach called “Point Break Surf Shop”. 
//Johnny sells surfboards in 4 three sizes: small (2 meters),
//medium (3 meters), and large (4 meters) and squirrel surf(50cm). The cost of one small surfboard is $175.00,
//one medium is $190.00, and one large is $200.00, squirrel size is $100.00
//Write a program that will make the surf shop operational.  
//Your program should allow the user to do the following:
// 1. Buy any surfboard in any sizeand in any quanity.
// 2. At any time show the total number of surfboards of each size sold.
// 3. At any time show the total money made.

// header files
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cctype>
#include <stdlib.h>

using namespace std;		// avoid typing std always

// user defined functions
void ShowUsage();
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& isquirrel);
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int isquirrel);
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int isquirrel);


void ShowUsage()		//show the user how to use the program
{
	// welcome message
	int a = 0;
	const int b = 60;
	const int c = 5;
	char star = '*';
	while (a < b)
	{
		cout << star;
		a++;
	}
	cout << endl;
	a = 0;
	while (a < c)
	{
		cout << star;
		a++;
	}
	cout << " Welcome to my Johnny Utah's PointBreak Surf Shop ";
	a = 0;
	while (a < c)
	{
		cout << star;
		a++;
	}
	a = 0;
	cout << endl;
	while (a < b)
	{
		cout << star;
		a++;
	}
	cout << endl << endl << endl;
	// welcome message

	cout << "To show program usage 'S'" << endl;
	cout << "To purchase a surfboard press 'P'" << endl;
	cout << "To display current purchases press 'C'" << endl;
	cout << "To display total amount due press 'T'" << endl;
	cout << "To quit the program press 'Q'" << endl << endl;
}

// a function to sell surfboards
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& isquirrel)
{
	int num = 0;
	string size;
	cout << "Please enter the quanity and type"
		<< "(S = small, M = medium, L = large, Q = squirrel surfing)"
		<< "of surfboard you would like to purchase :";
	cin >> num >> size;

	// to decrease cases 
	transform(size.begin(), size.end(), size.begin(), toupper);
	bool size1 = (size == "S");
	bool size2 = (size == "M");
	bool size3 = (size == "L");
	bool size4 = (size == "Q");

	if (size1)		// for small size
	{
		iTotalSmall = iTotalSmall + num;
	}
	else if (size2)		// for medium size
	{
		iTotalMedium = iTotalMedium + num;
	}
	else if (size3)			// for large size
	{
		iTotalLarge = iTotalLarge + num;
	}
	else if (size4)		// for squirrel size
	{
		isquirrel = isquirrel + num;
	}
	else
	{
		iTotalSmall = iTotalMedium = iTotalLarge = isquirrel = 0;		// for wrong input
	}
	cout << endl << endl;
}

//function to show the number of surfboards of each size sold
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int isquirrel)
{
	// if conditions
	// this way if users does not choose a specific size at all
	// it will show no purchase

	if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0 && isquirrel == 0)
	{
		cout << "No purchases made yet." << endl;
	}

	if (iTotalSmall > 0)
	{
		cout << "The total number of small surfboards is " << iTotalSmall << endl;
	}
	if (iTotalMedium > 0)
	{
		cout << "The total number of medium surfboards is " << iTotalMedium << endl;
	}
	if (iTotalLarge > 0)
	{
		cout << "The total number of large surfboards is " << iTotalLarge << endl;
	}
	if (isquirrel > 0)
	{
		cout << "The total number of squirrel surfboards is " << isquirrel << endl;
	}
	cout << endl;
}

//a function to show the total amount of money made
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int isquirrel)
{
	//prices based on sizes.
	const int Small = 175;
	const int Medium = 190;
	const int Large = 200;
	const int squirrel = 100;

	double sprice, mprice, lprice, sqprice, total;
	sprice = mprice = lprice = sqprice = total = 0;

	// total prices for all sizes
	sprice = Small * iTotalSmall;
	mprice = Medium * iTotalMedium;
	lprice = Large * iTotalLarge;
	sqprice = squirrel * isquirrel;
	total = sprice + mprice + lprice + sqprice;		//total amount due


	// showing to decimal places
	cout << fixed;
	cout << setprecision(2);


	if (sprice > 0)
	{
		cout << "The total number of small surfboards is "
			<< iTotalSmall << " at a total of $"
			<< sprice << endl;
	}
	if (mprice > 0)
	{
		cout << "The total number of medium surfboards is "
			<< iTotalMedium << " at a total of $"
			<< mprice << endl;
	}
	if (lprice > 0)
	{
		cout << "The total number of large surfboards is "
			<< iTotalLarge << " at a total of $"
			<< lprice << endl;
	}
	if (sqprice > 0)
	{
		cout << "The total number of squirrel surfboards is "
			<< isquirrel << " at a total of $"
			<< sqprice << endl;
	}
	if (total > 0)
	{
		cout << "Amount due: $" << total << endl;
	}
	if (total == 0)
	{
		cout << "No purchases made yet." << endl;
	}
	cout << endl;
}

int main()
{
	ShowUsage();		// declaring funcitons

	int smallnum = 0;
	int mediumnum = 0;
	int largenum = 0;
	int sqnum = 0;

	bool truthh = true;

	while (truthh)
	{
		string select;
		cout << "Please enter selection: ";
		cin >> select;
		transform(select.begin(), select.end(), select.begin(), toupper);
		bool truth = (select == "S");
		bool truth1 = (select == "P");
		bool truth2 = (select == "C");
		bool truth3 = (select == "T");
		bool truth4 = (select == "Q");

		if (truth)
		{
			system("CLS");
			cout << flush;
			ShowUsage();
		}
		if (truth1)
		{
			MakePurchase(smallnum, mediumnum, largenum, sqnum);
		}
		else if (truth2)
		{
			DisplayPurchase(smallnum, mediumnum, largenum, sqnum);
		}
		else if (truth3)
		{
			DisplayTotal(smallnum, mediumnum, largenum, sqnum);
		}
		else if (truth4)
		{
			cout << "Thank you" << endl;
			truthh = false;		//end loop
		}
	}
}