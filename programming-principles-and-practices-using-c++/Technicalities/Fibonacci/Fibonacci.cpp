#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v);
vector<int> fibonacci(int x, int y, vector<int> v, int n);
vector<int> reverse_v(vector<int> v);
void reverse_r(vector<int>& v);

int main()
{
	vector<int> v;
	v = fibonacci(1, 2, v, 5);
	print(v);
	vector<int> v2;
	v2 = fibonacci(1, 2, v, 5);
 	reverse_r(v2);
	print(v2);
	vector<int> rev;
	rev = reverse_v(rev);
	print(rev);

	return 0;
}

vector<int> reverse_v(vector<int> v)
{
	reverse(v.begin(), v.end());

	return v;
}

void reverse_r(vector<int>& v)
{
	reverse(v.begin(), v.end());
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