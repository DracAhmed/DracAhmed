//A cheese container can hold 2.76 kg of cheese. 
//Each evening, a fromager ships containers of cheese to a local grocery store. 
//The cost of producing one container of cheese is $4.12, 
//and the profit of each container of cheese is $1.45.
// Input_week_2.txt file content: * 79 15 33

#include <iostream>
#include<string>
#include<fstream>   //header for I/O
#include<iomanip>		// header for parametic manipulation

using namespace std;

const string Input = "Input_week_2.txt";		// input file
const string Output = "Output_week_2.txt";		// output file

int main()
{
	ifstream inputfile;
	ofstream outputfile;
	inputfile.open(Input);
	if (!inputfile)
	{
		cout << "error in input file" << endl;		// in case input file is not found
	}
	outputfile.open(Output);
	if (!outputfile)
	{
		cout << "error in output" << endl;		// in case output file is not found
	}
	////////////



	string asterisk;
	int a = 0;
	int Star1 = 0;
	int Star2 = 0;
	int Star3 = 0;
	inputfile >> asterisk >> Star1 >> Star2 >> Star3; 	//input from the txt file
	while (a <= Star1)
	{
		outputfile << asterisk;		// while loop to get asterisk for the code
		cout << asterisk;
		a = a + 1;
	}
	cout << endl;
	a = 0;
	while (a <= Star2) 
	{
		outputfile << asterisk;		// this code will show the result in the output, which helps further coding the code
		cout << asterisk;
		a = a + 1;
	}
	cout << " Cheese container business ";
	a = 0;
	while (a <= Star3)
	{
		outputfile << asterisk;
		cout << asterisk;
		a = a + 1;
	}
	cout << endl;
	a = 0;
	while (a <= Star1)
	{
		outputfile << asterisk;
		cout << asterisk;
		a = a + 1;
	}

	///////
	// input txt line 2.76 4.12 1.45
	// code to find container number, cost and profit starting from here
	
	double cheese = 0;			// cheese in one container
	double cost = 0;			// cost for one container
	double profit = 0;			// profit per container
	inputfile>> cheese >> cost >> profit;
	cout << endl <<"Please enter the total number of kilograms of cheese produced: ";
	
	double Cheesekg = 0;		// cheese can be decimal; that's why double
	int container = 0;			// container is integer always. There is nothing like a half container
	double Totalcost = 0;		// cost can be decimal
	double TotalProfit = 0;		// profit can be decimal too
	
	cin >> Cheesekg;
	
	container = Cheesekg / cheese;		// 1 container can hold 2.76 kg cheese; so, by dividing the total cheese with it will give the container number
	if (container*cheese < Cheesekg)
	{
		container = (Cheesekg / cheese)+1;	// there is a case where there is still a bit cheese left, but it will not fill the container
	}										// but you still need a container
	else
	{
		container = (Cheesekg / cheese);		// when no more cheese is left
	}
	
	// input txt file line 34 27 23
	int S1 = 0;
	int S2 = 0;
	int S3 = 0;
	inputfile >> S1 >> S2 >> S3;
	cout << "The number of containers to hold the cheese is : "<< setw(S1) << container << endl;
	
	// setw is used to present them all in the same line
	
	Totalcost = cost * container;
	cout << "The cost of producing " << to_string(container) << " container(s) of cheese is: "<<setw(S2) << "$" << Totalcost << endl;
	
	TotalProfit = profit * container;
	cout << "The profit from producing " << to_string(container) << " container(s) of cheese is: "<< setw(S3)<<"$" << TotalProfit << endl;
	
	inputfile.close();
	outputfile.close();
	return 0;
}

