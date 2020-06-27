#include <iostream>
#include <random>

using namespace std;

int main()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(0, 100);
	for (int i = 0; i < 10; i++)
	{
		cout << dist(mt) << endl;
	}
}