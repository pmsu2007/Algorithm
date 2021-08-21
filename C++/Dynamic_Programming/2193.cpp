/*
백준 2193번
이친수

1. 0으로 시작 X
2. 1이 두번연속 나오지 않는다.
*/

#include <iostream>

long long memo[91][2] = { 0, };

long long DP(int x)
{
	memo[1][0] = 0;
	memo[1][1] = 1;

	for (int i = 2; i <= x; i++)
	{
		if (memo[i - 1][0] != 0)
		{
			memo[i][1] += memo[i - 1][0];
			memo[i][0] += memo[i - 1][0];
		}
		if (memo[i - 1][1] != 0)
		{
			memo[i][0] += memo[i-1][1];
		}
	}
	return memo[x][0] + memo[x][1];
}

int main()
{
	int input;
	std::cin >> input;

	std::cout << DP(input);
	return 0;
}


/*
1
[1][1] = 1
[1][0] = 0
10
[2][1] = 0
[2][0] = 1
100
101
[3][1] = 1
[3][0] = 1
1001 
1000
1010
[4][1] = 1
[4][0] = 2


0으로 끝나면 2개
1로 끝나면 1개
*/
