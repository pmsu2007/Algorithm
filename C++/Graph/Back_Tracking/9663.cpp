/*
���� 9663��
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
	// ���� ü���� ��ġ�� �� ����
	if (visited[col] == true)
		return false;
	// ���� ü���� ��ġ�� �밢�� ����
	for (int i = row - 1; i >= 1; i--)
	{
		if (abs(row - i) == abs(col - arr[i]))
			return false;
	}

	return true;
}

/*
cnt : ��
i : ��
arr : ü�� ��ġ
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

	for (int i = 1; i <= N; i++) // �� ��� �� �˻�
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