/*
백준 11047번
동전 0
*/

#include <iostream>
#include <vector>

using namespace std;

int N, K;

int main()
{
	cin >> N >> K;
	
	vector<int> money(N);

	for (int i = 0; i < N; i++)
	{
		cin >> money[i];
	}

	int ans = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		ans += K / money[i];
		if (K / money[i] != 0)
			K %= money[i];
	}

	cout << ans << '\n';
}