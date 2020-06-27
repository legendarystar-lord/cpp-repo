#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> n;
vector<double> a;

void enter_values()
{
	string s;
	while (cin >> s && s != "done")
	{
		n.push_back(s);
	}

	for (int i = 0; i < n.size(); i++)
	{
		double d;
		cin >> d;
		a.push_back(d);
	}
}

void print(const vector<string>& n, const vector<double>& a)
{
	for (int i = 0; i < n.size(); i++)
	{
		cout << n[i] << " - " << a[i] << endl;
	}

	cout << endl;
}

int find_index(const vector<string>& vec, const string& s)
{
	for (int i = 0; i < vec.size(); ++i) 
	{
		if (vec[i] == s)
		{
			return i;
		}
	}
}

int main()
{
	enter_values();
	cout << "Entered like this:\n";
	print(n, a);

	vector<string> name_orig = n;
	vector<double> age_orig = a;
	sort(n.begin(), n.end());
	print(n, a);
	for (int i = 0; i < n.size(); ++i)
	{
		a[i] = age_orig[find_index(name_orig, n[i])];
	}

	cout << "\nAfter sorting:\n";
	print(n, a);
}