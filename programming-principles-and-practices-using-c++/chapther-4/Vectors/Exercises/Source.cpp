#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<iomanip>

using namespace std;

void Median(vector<double> sequence);
void Distances(vector<double> distances);
void GuessNumber();
void VerySimpleCalculator();
void DigitConverter();
void MiniCalculator();
void DoubleUp();
void WheatChessboardProblemIntAndDbl();

int main()
{
	int exercise;
	cin >> exercise;
	switch (exercise)
	{
	case 2:
	{
		vector<double> sequence;
		Median(sequence);
		break;
	}
	case 3:
	{
		vector<double> distances;
		Distances(distances);
		break;
	}
	case 4:
		GuessNumber();
		break;
	case 5:
		VerySimpleCalculator();
		break;
	case 6:
		DigitConverter();
		break;
	case 7:
		MiniCalculator();
		break;
	case 8:
		DoubleUp();
		break;
	case 9:
		WheatChessboardProblemIntAndDbl();
		break;
	default:
		break;
	}



	return 0;
}

void WheatChessboardProblemIntAndDbl()
{
	int squaresCount = 1;
	int grains = 1;
	while (true)
	{
		if (grains * 2 == -INT_MIN)
		{
			cout << "Max grains with int: " << grains << "\n";
			cout << "Max squares with int: " << squaresCount << "\n";
			break;
		}
		grains *= 2;
		squaresCount++;
	}

	double grainsDbl = 1.0;
	int squaresCountDbl = 1;
	while (true)
	{
		if (squaresCountDbl == 64)
		{
			// cout << fixed << showpoint;
			// cout << setprecision(1);
			cout << "Max grains with double: " << fixed << setprecision(0) << grainsDbl << "\n";
			cout << "Max squares with double: " << squaresCountDbl << "\n";
			break;
		}
		grainsDbl *= 2.0;
		squaresCountDbl++;
	}
}

void DoubleUp()
{
	int squaresCount = 1;
	int grains = 1;
	int squaresFor1k = 0;
	int squaresFor1m = 0;
	int squaresFor1b = 0;

	while (true)
	{
		grains *= 2;
		squaresCount++;
		if (grains >= 1000000000)
		{
			squaresFor1b = squaresCount;
			break;
		}
		if (grains >= 1000000 && squaresFor1m == 0)
		{
			squaresFor1m = squaresCount;
		}
		if (grains >= 1000 && squaresFor1k == 0)
		{
			squaresFor1k = squaresCount;
		}
	}

	cout << "Amount of squares required for 1,000 grains of rice: " << squaresFor1k << "\n";
	cout << "Amount of squares required for 1,000,000 grains of rice: " << squaresFor1m << "\n";
	cout << "Amount of squares required for 1,000,000,000 grains of rice: " << squaresFor1b << "\n";
}

void MiniCalculator()
{
	string input[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> input[i];
	}
	vector<string> nums = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	string numberAsStr1 = input[0];
	string numberAsStr2 = input[1];
	vector<string>::iterator it1 = find(nums.begin(), nums.end(), numberAsStr1);
	vector<string>::iterator it2 = find(nums.begin(), nums.end(), numberAsStr2);
	// cout << (it - nums.begin()) << "\n";
	int num1 = (it1 - nums.begin());
	int num2 = (it2 - nums.begin());
	if (input[2] == "+")
	{
		cout << "The sum of " << num1 << " and " << num2 << " is " << num1 + num2 << "\n";
	}
	else if (input[2] == "-")
	{
		cout << "The difference of " << num1 << " and " << num2 << " is " << num1 - num2 << "\n";
	}
	else if (input[2] == "*")
	{
		cout << "The product of " << num1 << " and " << num2 << " is " << num1 * num2 << "\n";
	}
	else if (input[2] == "/")
	{
		cout << "The quotient of " << num1 << " and " << num2 << " is " << num1 / num2 << "\n";
	}
}

void DigitConverter()
{
	vector<string> nums = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	int number;
	cin >> number;
	cout << nums[number] << "\n";
	string numberAsStr;
	cin >> numberAsStr;
	vector<string>::iterator it = find(nums.begin(), nums.end(), numberAsStr);
	cout << (it - nums.begin()) << "\n";
}

void VerySimpleCalculator()
{
	string input[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> input[i];
	}
	double num1 = stod(input[0]);
	double num2 = stod(input[1]);
	if (input[2] == "+")
	{
		cout << "The sum of " << num1 << " and " << num2 << " is " << num1 + num2 << "\n";
	}
	else if (input[2] == "-")
	{
		cout << "The difference of " << num1 << " and " << num2 << " is " << num1 - num2 << "\n";
	}
	else if (input[2] == "*")
	{
		cout << "The product of " << num1 << " and " << num2 << " is " << num1 * num2 << "\n";
	}
	else if (input[2] == "/")
	{
		cout << "The quotient of " << num1 << " and " << num2 << " is " << num1 / num2 << "\n";
	}
}

void GuessNumber()
{
	int number;
	cout << "Choose a number from 1 to 100" << "\n";
	cin >> number;
	int lowRange = 1;
	int highRange = 100;
	int possibleGuesses = highRange + lowRange - 1;
	int yourGuess;
	int playerAnswer;

	do
	{
		possibleGuesses = highRange + lowRange - 1;
		yourGuess = (int)ceil(possibleGuesses / 2.0);

		cout << "Is your number " << yourGuess << " ?" << "\n";
		cout << "Press (1)Yes (2)Guess a lower number (3)Guess a higher number" << "\n";
		cin >> playerAnswer;

		if (playerAnswer == 3)
		{
			lowRange = yourGuess + 1;
		}
		else if (playerAnswer == 2)
		{
			highRange = yourGuess - 1;
		}


	} while (playerAnswer != 1);

	cout << "Your number is " << yourGuess << "!" << "\n";

}

void Distances(vector<double> distances)
{
	for (double temp; cin >> temp;)
	{
		distances.push_back(temp);
	}
	double total;
	for (auto& i : distances)
	{
		total += i;
	}
	cout << total << "\n";

	double smallestDist = DBL_MAX;

	for (int i = 0; i < distances.size() - 1; i++)
	{
		if (distances[i] + distances[i + 1] < smallestDist)
		{
			smallestDist = distances[i] + distances[i + 1];
		}
	}

	cout << smallestDist << "\n";
}

void Median(vector<double> sequence)
{
	for (double temp; cin >> temp;)
	{
		sequence.push_back(temp);
	}
	sort(sequence.begin(), sequence.end());
	if (sequence.size() % 2 == 1)
	{
		cout << sequence[sequence.size() / 2] << "\n";
	}
	else
	{
		cout << (sequence[sequence.size() / 2 - 1] + sequence[sequence.size() / 2]) / 2 << "\n";
	}
}