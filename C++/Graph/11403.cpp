/*
백준 11403번
경로 찾기
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 10000

using namespace std;

vector<vector<int>> map(101, vector<int>(101));

int main()
{
	int vertexNum;

	cin >> vertexNum;

	for (int i = 1; i <= vertexNum; i++)
	{
		for (int j = 1; j <= vertexNum; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0) map[i][j] = INF;
		}
	}

	// k = 거쳐가는 노드
	for (int k = 1; k <= vertexNum; k++) {
		// i = 출발 노드
		for (int i = 1; i <= vertexNum; i++) {
			// j = 도착 노드
			for (int j = 1; j <= vertexNum; j++) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	for (int i = 1; i <= vertexNum; i++)
	{
		for (int j = 1; j <= vertexNum; j++)
		{
			if (map[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << 1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}