/*
���� 2309��
�ϰ� ������
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
				if (k != i && k != j) // i,j �ε����� �����ϰ� ���ϱ�
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
9���� 7�� �̴� ����� �� 9C7 = 9C2
*/