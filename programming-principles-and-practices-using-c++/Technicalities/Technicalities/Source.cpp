#include<iostream>

using namespace std;

void swap_v(int a, int b);
void swap_r(int& a, int& b);
void swap_cr(const int& a, const int& b);

namespace X
{
	int var = 0;
	void print()
	{
		cout << var << endl;
	}
}

namespace Y
{
	int var;
	void print()
	{
		cout << var << endl;
	}
}

namespace Z
{
	int var;
	void print()
	{
		cout << var << endl;
	}
}



int main()
{
	int x = 7;
	int y = 9;
	swap_v(x, y);
	cout << "x = " << x << " y = " << y << endl;
	swap_v(7, 9);
	swap_r(x, y);
	cout << "x = " << x << " y = " << y << endl;
	const int cx = 7;
	const int cy = 9;
	swap_v(cx, cy);
	swap_v(7.7, 9.9);
	double dx = 7.7;
	double dy = 9.9;

	cout << endl;

	X::var = 7;
	X::print();
	using namespace Y;
	var = 9;
	print();
	{
		using Z::var;
		using Z::print;
		var = 11;
		print();
	}
	print();
	X::print();


	return 0;
}

void swap_v(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap_cr(const int& a, const int& b)
{
	/*int temp = a;
	a = b;
	b = temp;*/
}