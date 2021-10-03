/*
���� 11724��
���� ����� ����
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

bool dfs(int vertex)
{
	if (!visited[vertex])
	{
		visited[vertex] = true;

		for (int i = 0; i < graph[vertex].size(); i++)
		{
			int y = graph[vertex][i];
			if (!visited[y])
				dfs(y);
		}
		return true;
	}
	else
		return false;
}

int main()
{
	int vertex, edge;
	cin >> vertex >> edge;

	for (int i = 0; i < edge; i++)
	{
		int first, second;
		cin >> first >> second;
		graph[first].push_back(second);
		graph[second].push_back(first);
	}

	for (int i = 1; i <= vertex; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	int ans = 0;

	for (int i = 1; i <= vertex; i++)
	{
		if (dfs(i))
			ans++;
	}

	cout << ans;

}

/*
�Է����� �־��� ���� ������ ���ٰ��ؼ� �ش� ��尡 ���� ���� �ƴ�.
*/