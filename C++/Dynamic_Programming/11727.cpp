/*
백준 11727번
2*n 타일링 2
*/

#include <iostream>

int memo[10001];


int DP(int x)
{
	memo[1] = 1;
	memo[2] = 3;

	for (int i = 3; i <= x; i++)
	{
		memo[i] = (memo[i - 1] + memo[i - 2] * 2) % 10007;
	}
	return memo[x];
}
int main()
{
	int x;
	std::cin >> x;

	DP(x);

	std::cout << memo[x];
}
