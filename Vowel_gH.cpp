#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// these constants are for the asterisk and dot used in the program
const int star1 = 59;
const int star2 = 11;
const int dot = 40;
const int dot1 = 39;


int main(int argc, char* argv[])
{
	// The executable name and at least one argument?
	if (argc < 2)
	{
		cout << "Error with input agruments" << endl;
		return 0;
	}

	// For debugging purposes only
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << ' ';		//this way program will print exactly shown in example
		//cout << i << ":" << argv[i] << endl; this will show the name in two seperate line
	}

	ifstream inFile;
	inFile.open(argv[1]);

	// if the file does not open
	if (!inFile)
	{
		cout << "Error with file name.." << endl;
		return 1;
	}

	cout << endl;
	// setfill and setw will print asterisk and dot

	cout << setfill('*') << '*' << setw(star1) << '*' << endl;
	cout << '*' << setw(star2) << '*';
	cout << " Welcome to my Letter Count Program ";
	cout << '*' << setw(star2) << '*' << endl;
	cout << '*' << setw(star1) << '*' << endl << endl;
	cout << "Analyzing file 'Constitution_of_the_United_States.html'..." << endl << endl;

	int a = 0;
	int e = 0;
	int i = 0;
	int o = 0;
	int u = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	string A = argv[1];
	while (getline(inFile, A))
	{
		for (int q = 0; q < A.length(); q++)		// length() finds out string length
		{
			switch (toupper(A[q]))		// converting all to uppercase, this way I don't have to consider 5 lowercase
			{
			case 'A':			// vowel a,e,i,o,u
				a = a + 1;
				break;
			case 'E':
				e = e + 1;
				break;
			case 'I':
				i = i + 1;
				break;
			case 'O':
				o = o + 1;
				break;
			case 'U':
				u = u + 1;
				break;
			case 'B':
				b = b + 1;
				break;
			case 'C':
				c = c + 1;
				break;
			case 'D':
				d = d + 1;
				break;
			}
		}
	}

	//out put command
	cout << setfill('.');
	cout << "The number of A's: " << '.' << setw(dot) << '.' << a << endl;
	cout << "The number of E's: " << '.' << setw(dot) << '.' << e << endl;
	cout << "The number of I's: " << '.' << setw(dot) << '.' << i << endl;
	cout << "The number of O's: " << '.' << setw(dot) << '.' << o << endl;
	cout << "The number of U's: " << '.' << setw(dot) << '.' << u << endl;

	// total vowel number
	int total = a + e + i + o + u;
	cout << "The vowel count is: " << '.' << setw(dot1) << '.' << total << endl<<endl;

	cout << "The number of B's: " << '.' << setw(dot) << '.' << b << endl;
	cout << "The number of C's: " << '.' << setw(dot) << '.' << c << endl;
	cout << "The number of D's: " << '.' << setw(dot) << '.' << d << endl;

	inFile.close();
	return 2;
}
