/*
백준 15652번
N과 M (4)
*/

#include <iostream>

using namespace std;

int arr[9];

int N, M;

void dfs(int num, int cnt)
{
	if (M == cnt)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = num; i <= N; i++)
	{
			arr[cnt] = i;
			dfs(i, cnt + 1);
	}
}

int main()
{
	cin >> N >> M;
	dfs(1, 0);
}