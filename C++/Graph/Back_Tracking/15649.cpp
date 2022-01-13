/*
���� 15649��
N�� M(1)
*/

#include <iostream>

using namespace std;

int arr[9];
bool visited[9];
int N, M;

void dfs(int cnt)
{
	if (M == cnt)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;

	dfs(0);
}