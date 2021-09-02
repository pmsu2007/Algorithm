/*
백준 10815번
숫자 카드
*/

#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> origin;
int DP[5000001];

int binarySearch(int target)
{
	int low = 0;
	int high = origin.size() - 1;
	if (DP[target])
		return 1;
	else
	{
		while (low <= high)
		{
			int middle = (low + high) / 2;
			if (target == origin[middle])
			{
				DP[target] = 1;
				return 1;
			}
			else if (target > origin[middle])
				low = middle + 1;
			else
				high = middle - 1;
		}

		return 0;
	}
}

int main()
{
	int N;
	std::cin >> N;

	
	int input;
	for (int i = 0; i < N; i++)
	{
		std::cin >> input;
		origin.push_back(input);
	}

	std::sort(origin.begin(), origin.end());

	int M;
	std::cin >> M;

	for (int i = 0; i < M; i++)
	{
		std::cin >> input;
		std::cout << binarySearch(input) << " ";
	}

	return 0;
}
