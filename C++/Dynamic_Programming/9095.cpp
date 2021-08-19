/*
백준 9095번
1, 2, 3 더하기
*/

#include <iostream>

int memo[12];

int DP(int x)
{
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 4;

	for (int i = 4; i <= x; i++)
	{
		memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
	}

	return memo[x];
}

int main()
{
	int test_case;
	std::cin >> test_case;

	DP(11);

	while (test_case--)
	{
		int input;
		std::cin >> input;
		std::cout << memo[input];
	}
	return 0;
}