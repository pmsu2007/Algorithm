/*
���� 10844��
���� ��� ��
*/

#include <iostream>

int length[101][10];


int DP(int x)
{
	length[1][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		length[1][i] = 1;
	}

	for (int i = 2; i <= x; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				length[i][j] = length[i-1][j + 1];
			else if (j > 0 && j < 9)
				length[i][j] = length[i-1][j - 1] + length[i-1][j + 1];
			else
				length[i][j] = length[i-1][j - 1];
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += length[x][i];
	}
	return sum;
}


int main()
{
	int x;
	std::cin >> x;


	std::cout << DP(x);
	return 0;
}

/* 
���� �ڸ��� 0,9�� ������ -1�� ���ش�
2�� 0�� 1�� ����� 1�� 0�� �����
7�� 9�� 8�� ����� 8�� 9�� �����

�� �ܰ踶�� 0,1,8,9 �� ���� ����
1
2
3
4
5
6
7
8
9

10 12
21 23
32 34
43 45
54 56
67 68
76 78
87 89
98

101 
*/
