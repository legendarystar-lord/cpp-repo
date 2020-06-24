#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main()
{
	vector<int> v;
	int target = 0;
	int x = 0;

	cin >> target;
	while (cin>>x)
	{
		v.push_back(x);
	}

	twoSum(v, target);
}

vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> twoSum;

	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				twoSum.push_back(i);
				twoSum.push_back(j);
				return twoSum;
			}
		}
	}
}