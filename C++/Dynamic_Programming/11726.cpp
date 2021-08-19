/*
백준 11726번
2*n 타일링
*/
#include <iostream>

int memo[1001];

int DP(int x)
{
	memo[1] = 1;
	memo[2] = 2;
	for (int i = 3; i <= x; i++)
	{
		memo[i] = (memo[i - 1] + memo[i - 2]) % 10007;
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
/*
피보나치 수열
왼쪽에 1*2 : 오른쪽엔 (n-1)*2 
왼쪽에 2*1 : 오른쪽엔 (n-2)*2

*/
