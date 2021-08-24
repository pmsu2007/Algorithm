/*
백준 1260번
DFS와 BFS
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

bool dfs_visited[1001];
bool bfs_visited[1001];

std::vector<int> dfs_graph[1001];
std::vector<int> bfs_graph[1001];

void dfs(int start)
{
	dfs_visited[start] = true;
	std::cout << start << " ";
	for (int i = 0; i < dfs_graph[start].size(); i++)
	{
		int y = dfs_graph[start][i];
		if (!dfs_visited[y])
			dfs(y);
	}
}

void bfs(int start)
{
	std::queue<int> q;
	q.push(start);
	bfs_visited[start] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		std::cout << x << " ";
		for (int i = 0; i < bfs_graph[x].size(); i++)
		{
			int y = bfs_graph[x][i];
			if (!bfs_visited[y])
			{
				q.push(y);
				bfs_visited[y] = true;
			}
		}
	}
}
int main()
{
	int vertex, edge, start;
	std::cin >> vertex >> edge >> start;

	while (edge--)
	{
		int x, y;
		std::cin >> x >> y;
		bfs_graph[x].push_back(y);
		bfs_graph[y].push_back(x);
		dfs_graph[x].push_back(y);
		dfs_graph[y].push_back(x);
	}

	for (int i = 1; i <= vertex; i++)
	{
		sort(bfs_graph[i].begin(), bfs_graph[i].end());
		sort(dfs_graph[i].begin(), dfs_graph[i].end());
	}

	dfs(start);
	std::cout << '\n';
	bfs(start);

	return 0;
}