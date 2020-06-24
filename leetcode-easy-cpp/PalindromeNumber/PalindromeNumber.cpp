#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(int x);

int main()
{
	int x = 0;
	cin >> x;
	isPalindrome(x);
}

bool isPalindrome(int x) {
	string s = to_string(x);
	string rev = s;
	reverse(rev.begin(), rev.end());
	if (rev == s)
	{
		return true;
	}
	else
	{
		return false;
	}
}