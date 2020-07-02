#include <iostream>
#include <vector>

using namespace std;

double maxv(vector<double>& v)
{
	double largest = DBL_MIN;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > largest)
		{
			largest = v[i];
		}
	}

	return largest;
}

int main()
{
	vector<double> nums;
	double d;
	while (cin >> d)
	{
		nums.push_back(d);
	}

	cout << maxv(nums) << endl;
}