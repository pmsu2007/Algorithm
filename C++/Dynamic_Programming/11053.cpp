/*
���� 11053��
���� �� �����ϴ� �κ� ����
*/
#include <iostream>
#include <vector>
#include <algorithm>


int memo[1001];


int main()
{
	int test_case;
	std::cin >> test_case;
	std::vector<int> origin;

	// ���Ϳ� ���� �����
	for (int i = 0; i < test_case; i++)
	{
		int input;
		std::cin >> input;
		origin.push_back(input);
	}

	std::fill_n(memo, 1001, 0);
	int ans = 0;

	for (int i = 1; i <= origin.size(); i++)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (origin[j] < origin[i - 1])
			{
				memo[i] = std::max(memo[i], memo[j + 1]);
			}
		}
		memo[i]++;
		ans = std::max(ans, memo[i]);
	}

	std::cout << ans;

}

/*

��� i < j�� ���� a[i] < a[j]�� ����

input:
30 10 20 50 60 70
ans:
10 20 50 60 70

input
1 3 5 2 3 4
ans
1 2 3 4

memo[i] i ��° ���� �������� ��

*/