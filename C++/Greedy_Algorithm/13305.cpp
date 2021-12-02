/*
백준 13305번
주유소
*/

#include <iostream>

using namespace std;

int N;
int dist[100000];
int price[100000];

int main()
{
	// 도시 개수
	cin >> N;
	// 거리 정보
	for (int i = 0; i < N - 1; i++)
	{
		cin >> dist[i];
	}
	// 주유소 가격
	for (int i = 0; i < N; i++)
	{
		cin >> price[i];
	}

	int i = 0;
	int j;
	long long cost = 0;
	while (i != N - 1)
	{
		long long gap = 0;
		for (j = i + 1; j <= N - 1; j++)
		{
			gap += dist[j-1];
			// 끝에 도달하거나 시작 주유소보다 가격이 낮은 주유소를 찾을 때
			if (price[i] > price[j] || j == N - 1)
			{
				cost += gap * price[i];
				i = j;
				break;
			}
		}

	}

	cout << cost << '\n';
}

/*
6
2 3 1 4 5
5 2 4 3 1 4
*/