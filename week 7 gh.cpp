//Your program must use one structure that contains the following member variables :
//1)a string data type that will hold the name of the bowler.
//2)a one - dimensional array of integers to store the bowler's 5 scores.
//3)an integer to hold the average bowling score.
//Your program must create and use an array of the structures mentioned previously.
//Your program must contain at least the following functions :
//an Boolean returning function called GetBowlingData to read and store data into an array of structures.
//The function should take as input parameters the file name and an empty array of structures, 
//which it should fill from the file(BowlingScores.txt  download) and return a status of either success or failure(i.e. true or false).
//a void function called GetAverageScore that is used to calculate the average bowling score.
//The function should take as input the array of structures which it should fill with the average score of each bowler.
//a void function called PrettyPrintResults to output the results, i.e.bowler name, scoresand average.


#include <iostream>
#include<fstream>
#include<iomanip>

using namespace std;

// input text file
const string bowler = "BowlingScores.txt";

// in the input file we have 10 rows and 6 columns
const int row_length = 10;
const int col_length = 6;

struct Bowling
{
	string bowlername;
	int    score;
	int    average;			
};

// function declare
bool GetBowlingData(const string bowler, Bowling name[row_length], Bowling score[row_length][col_length]);
void GetAverageScore(Bowling score[row_length][col_length], Bowling average[row_length]);
void PrettyPrintResults(Bowling name[row_length], Bowling score[row_length][col_length], Bowling average[row_length]);

// take data from the input file
bool GetBowlingData(const string bowler, Bowling name[row_length], Bowling score[row_length][col_length])
{
	ifstream inputfile;
	// opening the input file
	inputfile.open(bowler);

	// if the file does not open
	if (!inputfile)
	{
		cout << "file not opening" << endl;
		return false;
	}
	else
		// if file opens
	{
		cout << "\t\tWelcome to Array Problem Program with C++ struct" << endl;
	}
	// loop starts
	int i = 0;
	while (i < row_length)
	{
		// getting bowler name
		inputfile >> name[i].bowlername;
		// as we are using struct, we have to mention the variable names after the function variable, such as name[i].bowlername
		// name is a variable from the function and bowlername is from struct Bowling

		for (int j = 1; j < col_length; j++)
		{
			// getting score for each bowler. j starts from 1 as the first column is the name column
			inputfile >> score[i][j].score;
		}
		cout << endl;
		i = i + 1;
	}
	return true;
}
void GetAverageScore(Bowling score[row_length][col_length], Bowling average[row_length])
{
	int num = 5;
	// cause there are 5 scores for each player

	for (int i = 0; i < row_length; i++)
	{
		// this way sum will be zero before every iteration.
		int sum = 0;
		for (int j = 1; j < col_length; j++)
		{
			sum = sum + score[i][j].score;
		}

		average[i].average = sum / num;
	}
}

void PrettyPrintResults(Bowling name[row_length], Bowling score[row_length][col_length], Bowling average[row_length])
{
	cout << "Bowler Name" << "\t"
		<< "Score1" << "\t"
		<< "Score2" << "\t"
		<< "Score3" << "\t"
		<< "Score4" << "\t"
		<< "Score5" << "\t\t"
		<< "Average" << endl;
	for (int i = 0; i < row_length; i++)
	{
		// the last name in the file is too long, as a result, the result moves 1 tab. 
		// So, score1 shifts to score2, score2 to score3 and so on.
		//to keep the data organized, this if condition is running
		if (i <= 8)
		{
			cout << name[i].bowlername << "\t\t";
		}
		else
		{
			cout << name[i].bowlername << "\t";
		}


		for (int j = 1; j < col_length; j++)
		{
			cout << score[i][j].score << "\t";
		}
		cout << "\t" << average[i].average << endl;
	}
}

int main()
{
	Bowling name1[row_length];
	Bowling score_bowl[row_length][col_length];
	Bowling avg[row_length];

	GetBowlingData(bowler, name1, score_bowl);
	GetAverageScore(score_bowl, avg);
	PrettyPrintResults(name1, score_bowl, avg);

}

// important note: the average is taken an integer deliberately. 
// So, the average does not show the digits after the decimal point.
