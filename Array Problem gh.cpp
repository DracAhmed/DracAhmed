//Write a program to calculate a bowling league's average bowling scores.
//You will need to read the input data from the file BowlingScores.txt  
//You must use three arrays :
//1) one - dimensional array to store the bowler's names.
//2)(parallel) two - dimensional array to store the bowling scores.
//3) one - dimensional array to store the bowler's average score.
//Your program must contain at least the following functions :
//1)function called GetBowlingData to read and store data into two arrays.
//The function should take as input parameters the file name and both empty arrays, 
//which it should fill from the file and return a status of either success or failure(i.e. true or false)
//2)function called GetAverageScore that is used to calculate the average bowling score.
// The function should take as input the populated arrays and return the average score of each bowler in a separate array.
//3)function called PrettyPrintResults to output the results, 
//i.e., bowler name, scores and average.

#include <iostream>
#include<fstream>
#include<iomanip>

using namespace std;

// input text file
const string Input = "BowlingScores.txt";

// in the input file we have 10 rows and 5 columns
const int row_length = 10;
const int col_length = 6;


// function declare
void GetBowlingData(string bowler, string name[row_length], int score[row_length][col_length]);
void GetAverageScore(int score[row_length][col_length], double average[row_length]);
void PrettyPrintResults(string name[row_length], int score[row_length][col_length], double average[row_length]);

// take data from the input file
void GetBowlingData(string bowler, string name[row_length], int score[row_length][col_length])
{
	ifstream inputfile;
	// opening the input file
	inputfile.open(Input);

	// if the file does not open
	if (!inputfile)
	{
		cout << "error in input file" << endl;
	}
	else
		// if file opens
	{
		cout << "\t\tWelcome to Array Problem Program" << endl;
	}
	// loop starts
	int i = 0;
	while (i < row_length)
	{
		// getting bowler name
		inputfile >> name[i];

		for (int j = 1; j < col_length; j++)
		{
			// getting score for each bowler. j starts from 1 as the first column is the name column
			inputfile >> score[i][j];
		}
		cout << endl;
		i = i + 1;
	}
}



void GetAverageScore(int score[row_length][col_length], double average[row_length])
{
	int num = 5;
	// cause there are 4 scores for each player

	for (int i = 0; i < row_length; i++)
	{
		// this way sum will be zero before every iteration.
		double sum = 0;
		for (int j = 1; j < col_length; j++)
		{
			sum = sum + score[i][j];
		}

		average[i] = sum / num;
	}
}

void PrettyPrintResults(string name[row_length], int score[row_length][col_length], double average[row_length])
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
			cout << name[i] << "\t\t";
		}
		else
		{
			cout << name[i] << "\t";
		}


		for (int j = 1; j < col_length; j++)
		{
			cout << score[i][j] << "\t";
		}
		// setting precision to 2, 2 decimal place will show
		cout << fixed << setprecision(2);
		cout << "\t" << average[i] << endl;
	}
}

int main()
{
	string name1[row_length];
	int score_bowl[row_length][col_length];
	double avg[row_length];

	GetBowlingData(Input, name1, score_bowl);
	GetAverageScore(score_bowl, avg);
	PrettyPrintResults(name1, score_bowl, avg);

}

