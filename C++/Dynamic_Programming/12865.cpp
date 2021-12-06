/*
백준 12865번
평범한 배낭
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

int v[101];
int w[101];
int memo[101][100001];


void knapsack()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j >= w[i])
				memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - w[i]] + v[i]);
			else
				memo[i][j] = memo[i - 1][j];
		}
	}
}

int main()
{
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++)
	{
		cin >> w[i] >> v[i];
	}

	knapsack();

	cout << memo[N][K] << '\n';
}

/*
4 7
6 13
4 8
3 6
5 12

4 6
2 4
3 5
6 9
1 1

*/

