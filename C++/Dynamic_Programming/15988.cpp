/*
백준 15988번
1, 2, 3 더하기 3
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000009

int memo[1000001];

int DP(int x)
{
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 4;

	for (int i = 4; i <= x; i++)
	{
		memo[i] = (memo[i - 1] % MOD) + (memo[i - 2] % MOD)+ (memo[i - 3] % MOD) % MOD;
	}

	return memo[x];
}

int main()
{
	int test_case;
	std::cin >> test_case;

	std::vector<int> v;
	int input;
	for (int i = 0; i < test_case; i++)
	{
		std::cin >> input;
		v.push_back(input);
	}

	int max = *max_element(v.begin(), v.end());
	DP(max);

	for (auto i = v.begin(); i != v.end(); i++)
	{
		std::cout << memo[*i] << '\n';
	}
	
	return 0;
}