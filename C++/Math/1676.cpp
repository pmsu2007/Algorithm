/*
���� 1676��
���丮�� 0�� ����

10���� �������� �� ������ ������ ��
*/

#include <iostream>

int main() 
{
	int num;
	std::cin >> num;
	
	int arr[2] = { 0, 0 };

	for (int i = 2; i <= num; i++)
	{
		int j = i;
		while (j > 0) {
			if (j % 5 == 0)
			{
				arr[1]++;
				j = j / 5;
			}
			else if (j % 2 == 0)
			{
				arr[0]++;
				j = j / 2;
			}
			else
				break;
		}
	}

	int count = std::min(arr[0], arr[1]); 
	std::cout << count << '\n';
}

/*
�� i �� ���μ� ���� �ؼ� �迭�� ���� 
2�� 5 �� �ּ� ���� 0�� ����
*/