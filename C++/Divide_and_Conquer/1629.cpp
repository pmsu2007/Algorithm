/*
น้มุ 1629น๘
ฐ๖ผม
*/

#include <iostream>

using namespace std;

long long int target, power, mod;

long long int pow(long long int target, long long power)
{
	if (power == 0)
		return 1;
	else if (power == 1)
		return target;
	else if (power % 2 > 0)
		return pow(target, power - 1) * target;

	long long int half = pow(target, power / 2);
	half %= mod;

	return (half * half) % mod;
}

int main()
{
	cin >> target >> power >> mod;

	cout << pow(target, power) % mod;
}