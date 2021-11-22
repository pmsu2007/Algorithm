/*
백준 5585번
거스름돈
*/

#include <iostream>

using namespace std;

int main()
{
	int pay;
	cin >> pay;

	int change = 1000 - pay;

	int money[] = { 500, 100, 50, 10, 5, 1 };

	int ans = 0;

	for (auto i : money)
	{
		ans += change / i;
		if (change / i != 0)
			change %= i;
	}

	cout << ans << '\n';
}