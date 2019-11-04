#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

double Median(vector<double> sequence);

int main()
{
	//vector<double> sequence;
	//double median = Median(sequence);
	//
	//cout << median << "\n";

	vector<double> distances;
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



	return 0;
}

double Median(vector<double> sequence)
{
	for (double temp; cin >> temp;)
	{
		sequence.push_back(temp);
	}
	sort(sequence.begin(), sequence.end());
	if (sequence.size() % 2 == 1)
	{
		return sequence[sequence.size() / 2];
	}
	else
	{
		return (sequence[sequence.size() / 2 - 1] + sequence[sequence.size() / 2]) / 2;
	}
}