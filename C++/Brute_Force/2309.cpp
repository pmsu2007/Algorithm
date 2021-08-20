/*
백준 2309번
일곱 난쟁이
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int test_case = 9;

	std::vector<int> origin;
	std::vector<int> copy;

	while (test_case--)
	{
		int input;
		std::cin >> input;
		origin.push_back(input);
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			int sum = 0;
			std::vector<int> copy;
			for (int k = 0; k < 9; k++)
			{
				if (k != i && k != j) // i,j 인덱스만 제외하고 더하기
				{
					sum += origin[k];
					copy.push_back(origin[k]);
				}
			}
			if (sum == 100)
			{
				sort(copy.begin(), copy.end());
				for (auto l = copy.begin(); l != copy.end(); l++)
				{
					std::cout << *l << '\n';
				}
			}
		}
	}
}

/*
9명중 7명 뽑는 경우의 수 9C7 = 9C2
*/