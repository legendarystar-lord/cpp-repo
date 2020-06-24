#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int x = 0;
	cin >> x;
    int result = 0;
    while (x != 0) {
        int n = x % 10;
        x /= 10;
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && n > 7)) {
            return 0;
        }
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && n < -8)) {
            return 0;
        }
        result = result * 10 + n;
    }
    return result;
}