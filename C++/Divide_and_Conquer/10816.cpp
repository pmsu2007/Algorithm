/*
���� 10816��
���� ī�� 2
*/
#include <iostream>
#include <vector>
#include <algorithm>

int origin[500001];


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	
	int input;
	for (int i = 0; i < N; i++)
	{
		std::cin >> input;
		origin[i] = input;
	}

	std::sort(origin, origin + N);

	int M;
	std::cin >> M;
	
	for (int i = 0; i < M; i++)
	{
		std::cin >> input;
		std::cout << std::upper_bound(origin, origin + N, input) - std::lower_bound(origin, origin + N, input) << " ";
	}

	return 0;
}

/*
���� �� �� ���� ���� ���Դٰ� �������� �� �̺� Ž���� �ϸ� �ᱹ ��Ÿ���� �� ��ü�� ���� ���� �ǹǷ� �̺� Ž���� �ǹ̰� ����.
*/