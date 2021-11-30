/*
น้มุ 13023น๘
ABCDE
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[2000];
int n, m;

bool exist = false;


void dfs(int v, vector<int> visited, int depth)
{

	if (depth == 5)
	{
		exist = true;
		return;
	}

	visited.push_back(v);

	for (int i = 0; i < graph[v].size(); i++)
	{
		int next = graph[v][i];
		if (find(visited.begin(), visited.end(), next) == visited.end())
			dfs(next, visited, depth + 1);
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<int> temp;
	for (int i = 0; i < n; i++)
	{
		temp.clear();
		dfs(i, temp, 1);
		if (exist)
			break;
	}

	if (exist)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';

}