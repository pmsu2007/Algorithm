/*
백준 15990번
1, 2, 3 더하기 5

같은 수를 두 번 이상 연속해서 사용 X
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000009

int memo[100001][4];

void DP(int x)
{
	memo[1][1] = 1 , memo[1][2] = 0, memo[1][3] = 0; 
	memo[2][1] = 0 , memo[2][2] = 1, memo[2][3] = 0;
	memo[3][1] = 1 , memo[3][2] = 1, memo[3][3] = 1;

	for (int i = 4; i <= x; i++)
	{
		memo[i][1] = (memo[i - 1][2] + memo[i - 1][3]) % MOD;
		memo[i][2] = (memo[i - 2][1] + memo[i - 2][3]) % MOD;
		memo[i][3] = (memo[i - 3][1] + memo[i - 3][2]) % MOD;
	}

}


int main()
{
	int test_case;
	std::cin >> test_case;

	std::vector<int> v;
	while (test_case--)
	{
		int input;
		std::cin >> input;
		v.push_back(input);
	}
	int max = *max_element(v.begin(), v.end());
	DP(max);
	
	for (auto i = v.begin(); i != v.end(); i++)
	{
		int sum = 0;
		for (int j = 1; j < 4; j++)
		{
			sum += memo[*i][j];
			sum = sum % MOD;
		}
		std::cout << sum << '\n';
	}

	return 0;
}

/* 
1,2,3 의 합으로 나타내는데 같은 수를 두 번 이상 연속해서 사용하면 안 됨
0

1 [1][1] = 1
  [1][2] = 0
  [1][3] = 0

2  [2][1] = 0
   [2][2] = 1
   [2][3] = 0

1 2 [3][1] = 1
2 1 [3][2] = 1
3   [3][3] = 1

1 3     [4][1] = 2 // [3][2] + [3][3]
1 2 1   [4][2] = 0 // [2][1] + [2][3]
3 1     [4][3] = 1 // [1][1] + [1][2]

1 3 1
2 3 
2 1 2
3 2

1 2 3
1 2 1 2
1 3 2
2 1 3
2 1 2 1
2 3 1
3 1 2
3 2 1
*/