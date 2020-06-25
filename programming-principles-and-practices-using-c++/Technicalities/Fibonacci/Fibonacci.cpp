#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v);
vector<int> fibonacci(int x, int y, vector<int> v, int n);

int main()
{
	vector<int> v;
	v = fibonacci(1, 2, v, 10);
	print(v);

	return 0;
}

vector<int> fibonacci(int x, int y, vector<int> v, int n)
{
	v.push_back(x);
	v.push_back(y);
	for (int i = 1; i <= n; i++)
	{
		v.push_back(v[i - 1] + v[i]);
	}

	return v;
}

void print(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}

	cout << endl;
}