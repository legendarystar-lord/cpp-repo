#include <iostream>
#include <vector>

using namespace std;

struct str
{
	string longest;
	string shortest;
	string first;
	string last;
};

vector<int> num_of_chars(vector<string> s)
{
	vector<int> numchars;
	for (int i = 0; i < s.size(); i++)
	{
		numchars.push_back(s[i].length());
	}

	return numchars;
}

str comparer(vector<string> s)
{
	str compared;
	compared.longest = "";
	compared.shortest = s[0];
	compared.first = s[0];
	compared.last = s[0];

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i].length() > compared.longest.length())
		{
			compared.longest = s[i];
		}
		if (s[i].length() < compared.shortest.length())
		{
			compared.shortest = s[i];
		}
		if (string(s[i]) < compared.first)
		{
			compared.first = s[i];
		}
		if (string(s[i]) > compared.last)
		{
			compared.last = s[i];
		}
	}

	return compared;
}

void print(vector<int> v, str s)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	cout << "Longest: " << s.longest << "\n" << "Shortest: " << s.shortest << "\n" << "First: " << s.first << "\n"
		<< "Last: " << s.last << endl;
}

int main()
{
	vector<string> s;
	string w;
	while (cin >> w && w != "done")
	{
		s.push_back(w);
	}

	vector<int> v;
	v = num_of_chars(s);
	str compared;
	compared = comparer(s);
	print(v, compared);
}