/*
백준 15651번
N과 M (3)
*/

#include <iostream>

using namespace std;

int arr[8];
int N, M;

void dfs(int cnt)
{
	if (M == cnt)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		arr[cnt] = i;
		dfs(cnt + 1);
	}
}

int main()
{
	cin >> N >> M;

	dfs(0);
}