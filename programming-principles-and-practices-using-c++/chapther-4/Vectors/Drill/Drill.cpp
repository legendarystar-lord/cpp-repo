#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <float.h>
#include <iostream> 
#include <algorithm>
#include <string>

using namespace std;


bool nearlyEqual(double a, double b, double epsilon);

int main()
{
	double num1;
	double num2;
	while (cin >> num1 >> num2)
	{
		if (nearlyEqual(num1, num2, 0.01))
		{
			cout << "the numbers are almost equal" << "\n";
		}
	}

	double num;
	double maxNum = -DBL_MIN;
	double minNum = DBL_MAX;
	while (cin >> num)
	{
		if (num < minNum)
		{
			minNum = num;
			cout << "the smallest so far" << "\n";
		}
		else if (num > minNum)
		{
			minNum = num;
			cout << "the largest so far" << "\n";
		}
	}

	vector<double> units;
	for (string temp; cin >> temp; )
	{
		char unit = temp.back();
		string subStrTemp = temp.substr(0, temp.size() - 1);
		if (unit == 'm')
		{
			units.push_back(stod(temp));
		}
		else if (unit == 'n')
		{
			units.push_back(stod(temp) * 2.54);
		}
		else if (unit == 't')
		{
			units.push_back(stod(temp) * 2.54 * 12);
		}
	}

	sort(units.begin(), units.end());

	double max = -DBL_MIN;
	double min = DBL_MAX;
	double sum_of_elems = 0;

	for (int i = 0; i < units.size(); i++) {
		if (units[i] > max)
			max = units[i];
	}

	for (int i = 0; i < units.size(); i++) {
		if (units[i] < min)
			min = units[i];
	}

	for (auto& n : units)
		sum_of_elems += n;

	cout << max << "\n" << min << "\n" << units.size() << "\n" << sum_of_elems << "\n";

	for (auto i : units)
		cout << i << " ";


	return 0;
}

bool nearlyEqual(double a, double b, double epsilon)
{
	double absA = abs(a);
	double absB = abs(b);
	double diff = abs(a - b);

	if (a == b) { // shortcut, handles infinities
		return true;
	}
	else if (a == 0 || b == 0 || (absA + absB < DBL_MIN)) {
		// a or b is zero or both are extremely close to it
		// relative error is less meaningful here
		return diff < (epsilon * DBL_MIN);
	}
	else { // use relative error
		return diff / min((absA + absB), DBL_MAX) < epsilon;
	}
}