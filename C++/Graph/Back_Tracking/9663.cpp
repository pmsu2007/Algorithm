/*
백준 9663번
N-Queen
*/

#include <iostream>
#include <cmath>

using namespace std;

int N;
int ans = 0;
int arr[15];
int visited[15];


bool putChess(int row, int col)
{
	// 이전 체스가 위치한 열 제외
	if (visited[col] == true)
		return false;
	// 이전 체스가 위치한 대각선 제외
	for (int i = row - 1; i >= 1; i--)
	{
		if (abs(row - i) == abs(col - arr[i]))
			return false;
	}

	return true;
}

/*
cnt : 행
i : 열
arr : 체스 위치
*/
void dfs(int cnt)
{
	if (cnt == N + 1)
	{
		/*
		for (int i = 1; i <= N; i++)
			cout << arr[i] << " ";
		cout << '\n';
		*/
		ans++;
		return;
	}

	for (int i = 1; i <= N; i++) // 각 행당 열 검사
	{
		if (cnt == 1)
		{
			visited[i] = true;
			arr[cnt] = i;
			dfs(cnt + 1);
			visited[i] = false;
		}
		else if (putChess(cnt, i))
		{
			arr[cnt] = i;
			visited[i] = true;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> N;

	dfs(1);
	
	cout << ans;
}