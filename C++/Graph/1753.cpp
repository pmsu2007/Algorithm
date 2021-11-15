/*
백준 1753번
최단 경로
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define MAX_VERTEX 20001
#define MAX_EGDE 300001
#define INF 1000000

int vertex, edge;
vector<pair<int, int>> graph[MAX_VERTEX];



void dijkstra(int source)
{
	vector<int> dist(vertex + 1, INF);

	dist[source] = 0;

	int i;
	int u, v;
	int distu, distv;

	// dist가 가장 가까운 순으로 배치
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, source }); // dist, prev

	while (!pq.empty()) {
		u = pq.top().second; // vertex
		distu = pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[u].size(); i++)
		{
			v = graph[u][i].first;
			distv = distu + graph[u][i].second;
			if (dist[v] > distv)
			{
				dist[v] = distv;
				pq.push({ distv, v });
			}
		}
	}

	for (int i = 1; i <= dist.size(); i++)
	{

		if (dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
}


int main()
{
	int u, v, w;
	int source;

	cin >> vertex >> edge;
	cin >> source;
	for (int i = 0; i < edge; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	dijkstra(source);
}