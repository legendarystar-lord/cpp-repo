#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

void Median(vector<double> sequence);
void Distances(vector<double> distances);
void GuessNumber();
void VerySimpleCalculator();
void DigitConverter();
void MiniCalculator();
void DoubleUp();
void WheatChessboardProblemIntAndDbl();
void RockPaperScissors();
void Primes();
void PrimesMax();
void SieveOfEratosthenes();
void SieveOfEratosthenesMax();
bool isPrime(int n);
void PrimesToN();
void GetMode();

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
	case 10:
		RockPaperScissors();
		break;
	case 11:
		Primes();
		break;
	case 12:
		PrimesMax();
		break;
	case 13:
		SieveOfEratosthenes();
		break;
	case 14:
		SieveOfEratosthenesMax();
		break;
	case 15:
		PrimesToN();
		break;
	case 16:
		GetMode();
		break;
	default:
		break;
	}
	
	

	return 0;
}

void GetMode()
{
	int tempCount = 1, mode = 1;
	vector<int> nums;
	for (double temp; cin >> temp; )
	{
		nums.push_back(temp);
	}

	sort(nums.begin(), nums.end());

	int lastNumber = nums[0];

	for (int i = 1; i < nums.size(); ++i)
	{
		if (lastNumber == nums[i])
		{
			++tempCount;
		}
		else
		{
			lastNumber = nums[i];
			if (tempCount > mode)
			{
				mode = tempCount;
			}
			tempCount = 0;
		}
	}

	cout << mode << "\n";
}

bool isPrime(int n)
{
	// Corner case 
	if (n <= 1)
		return false;

	// Check from 2 to n-1 
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;

	return true;
}

void PrimesToN()
{
	int n;
	cin >> n;
	vector<int> primes;
	primes.push_back(2);
	int currentNum = 3;
	while (primes.size() < n)
	{
		if (isPrime(currentNum))
		{
			primes.push_back(currentNum);
		}

		currentNum++;
	}

	for (int i = 0; i < primes.size(); i++)
	{
		if (i % 10 == 0)
		{
			cout << "\n";
		}

		cout << setw(3) << primes[i] << " ";
	}

	cout << "\n" << primes.size() << "\n";
}

void SieveOfEratosthenesMax()
{
	int max;
	cin >> max;
	vector<int> sieve;
	vector<int> primes;

	for (int i = 1; i < max + 1; ++i)
	{
		sieve.push_back(i);
	}
	sieve[0] = 0;
	for (int i = 2; i < max + 1; ++i) 
	{
		if (sieve[i - 1] != 0) 
		{
			primes.push_back(sieve[i - 1]);
			for (int j = 2 * sieve[i - 1]; j < max + 1; j += sieve[i - 1])
			{
				sieve[j - 1] = 0;
			}
		}
	}
	for (int i = 0; i < primes.size(); i++)
	{
		if (i % 10 == 0)
		{
			cout << "\n";
		}
		cout << setw(10) << primes[i] << " ";
	}
}

void SieveOfEratosthenes()
{
	const int size = 100;
	int arr[size] = { 0 };
	for (int i = 2; i < size; i++) 
	{
		for (int j = i * i; j < size; j += i) 
		{
			arr[j - 1] = 1;
		}
	}
	for (int i = 1; i < size; i++) 
	{
		if (arr[i - 1] == 0)
		{
			cout << i << " ";
		}
	}
}

void PrimesMax()
{
	vector<int> primes;
	primes.push_back(2);
	int max;
	cin >> max;
	bool flag = false;
	for (int i = 3; i < max; i++)
	{
		for (int j = 0; j < primes.size(); j++)
		{
			if (i % primes[j] == 0)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			primes.push_back(i);
		}
		flag = false;
	}

	for (int i = 0; i < primes.size(); i++)
	{
		if (i % 10 == 0)
		{
			cout << "\n";
		}
		cout << setw(10) << primes[i] << " ";
	}

	cout << "\n";
}

void Primes()
{
	vector<int> primes;
	primes.push_back(2);
	bool flag = false;
	for (int i = 3; i < 100; i++)
	{
		for (int j = 0; j < primes.size(); j++)
		{
			if (i % primes[j] == 0)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			primes.push_back(i);
		}
		flag = false;
	}

	for (int i = 0; i < primes.size(); i++)
	{
		cout << primes[i] << " ";
	}

	cout << "\n";
}

void RockPaperScissors()
{
	vector<string> rps = { "Rock", "Paper", "Scissors" };
	srand(time(NULL));
	string input;
	cout << "Choose Rock, Paper or Scissors: " << "\n";
	cin >> input;
	while (input == "Rock" || input == "Paper" || input == "Scissors")
	{
		string compChoice = rps[rand() % 3];
		int playerChoice;
		if (input == "Rock")
		{
			playerChoice = 1;
		}
		else if (input == "Paper")
		{
			playerChoice = 2;
		}
		else if (input == "Scissors")
		{
			playerChoice = 3;
		}

		switch (playerChoice)
		{
		case 1:
			if (compChoice == "Rock")
			{
				cout << "The computer choose: " << compChoice << "\n";
				cout << "Tie!" << "\n";
			}
			else if (compChoice == "Paper")
			{
				cout << "The computer choose: " << compChoice << "\n";
				cout << "You lost!" << "\n";
			}
			else if (compChoice == "Scissors")
			{
				cout << "The computer choose: " << compChoice << "\n";
				cout << "You won!" << "\n";
			}
			break;
		case 2:
			if (compChoice == "Rock")
			{
				cout << "The computer choose: " << compChoice << "\n";
				cout << "You won!" << "\n";
			}
			else if (compChoice == "Paper")
			{
				cout << "The computer choose: " << compChoice << "\n";
				cout << "Tie!" << "\n";
			}
			else if (compChoice == "Scissors")
			{
				cout << "The computer choose: " << compChoice << "\n";
				cout << "You lost!" << "\n";
			}
			break;
		case 3:
			if (compChoice == "Rock")
			{
				cout << "The computer choose: " << compChoice << "\n";
				cout << "You lost!" << "\n";
			}
			else if (compChoice == "Paper")
			{
				cout << "The computer choose: " << compChoice << "\n";
				cout << "You won!" << "\n";
			}
			else if (compChoice == "Scissors")
			{
				cout << "The computer choose: " << compChoice << "\n";
				cout << "Tie!" << "\n";
			}
			break;
		default:
			break;
		}

		cout << "Choose Rock, Paper or Scissors: " << "\n";
		cin >> input;
	}
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

	for (size_t i = 0; i < distances.size() - 1; i++)
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