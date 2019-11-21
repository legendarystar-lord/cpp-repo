#include "std_lib_facilities.h"

using namespace std;

double ctok(double c);

int main()
{
	int exercise = 0;
	cin >> exercise;
	switch (exercise)
	{
	case 1:
	{
		try 
		{
			double c = 0.0;
			cin >> c;
			double k = ctok(c);
			cout << k << endl;
		}
		catch (exception& e) 
		{
			cerr << "Error: " << e.what() << endl;
			break;
		}
		catch (...)
		{
			cerr << "Unknown exception!\n";
			break;
		}
	}
	default:
		break;
	}


}

double ctok(double c)
{
	if (c < -273.15) error("Invalid input");
	double k = c + 273.15;
	return k;
}