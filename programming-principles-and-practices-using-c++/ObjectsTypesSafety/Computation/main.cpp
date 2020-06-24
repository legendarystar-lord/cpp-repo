#include <iostream>

using namespace std;

int main()
{
	int i = 0;
	while (i < 10)
	{
		cout << i << endl;
		++i;
	}

	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
	}
}

int square(int x)
{
	return x * x;
}