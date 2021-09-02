/*
백준 10816번
숫자 카드 2
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
수를 셀 때 같은 수가 나왔다고 양쪽으로 또 이분 탐색을 하면 결국 나타나는 수 전체에 대해 보게 되므로 이분 탐색의 의미가 없다.
*/