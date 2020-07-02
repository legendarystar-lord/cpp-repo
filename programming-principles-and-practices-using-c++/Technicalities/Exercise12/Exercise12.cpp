#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct elements
{
	double largest;
	double smallest;
	double median;
	double mean;
};

elements finder(vector<double> v)
{
	elements newElement;
	newElement.largest = DBL_MIN;
	newElement.smallest = DBL_MAX;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > newElement.largest)
		{
			newElement.largest = v[i];
		}
		if (v[i] < newElement.smallest)
		{
			newElement.smallest = v[i];
		}
	}

	newElement.mean = accumulate(begin(v), end(v), 0.0) / size(v);

	sort(v.begin(), v.end());
	if (v.size() % 2 == 0)
	{
		newElement.median = (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2;
	}
	else
	{
		newElement.median = v[v.size() / 2];
	}

	return newElement;
}

void print(elements e)
{
	cout << "Largest: " << e.largest << "\n" << "Smallest: " << e.smallest << "\n" << "Mean: " << e.mean << "\n" 
		<< "Median: " << e.median << endl;
}

int main()
{
	vector<double> nums;
	double d;
	while (cin >> d)
	{
		nums.push_back(d);
	}

	elements els = finder(nums);
	print(els);
}