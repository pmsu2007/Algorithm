/*
���� 13305��
������
*/

#include <iostream>

using namespace std;

int N;
int dist[100000];
int price[100000];

int main()
{
	// ���� ����
	cin >> N;
	// �Ÿ� ����
	for (int i = 0; i < N - 1; i++)
	{
		cin >> dist[i];
	}
	// ������ ����
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
			// ���� �����ϰų� ���� �����Һ��� ������ ���� �����Ҹ� ã�� ��
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