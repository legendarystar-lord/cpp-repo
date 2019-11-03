#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> words;

	for (string temp; cin>>temp; )
	{
		words.push_back(temp);
	}

	for (int i = 0; i < words.size(); i++)
	{
		if (i != 0 && words[i] == words[i - 1])
		{
			cout << "BLEEP" << " ";
		}
		else
		{
			cout << words[i] << " ";
		}
	}

	return 0;
}
