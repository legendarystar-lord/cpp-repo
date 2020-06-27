#include<iostream>
#include<vector>

using namespace std;

void enter_values(vector<double>& p, vector<double>& w)
{
	double d;
	while (cin >> d)
	{
		p.push_back(d);
	}

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int i = 0; i < p.size(); i++)
	{
		double d;
		cin >> d;
		w.push_back(d);
	}
}

double sum(vector<double> p, vector<double> w)
{
	double sum = 0;
	for (int i = 0; i < w.size(); i++)
	{
		sum += p[i] + w[i];
	}

	return sum;
}

int main()
{
	vector<double> price;
	vector<double> weight;

	enter_values(price, weight);
	cout << sum(price, weight) << endl;
}