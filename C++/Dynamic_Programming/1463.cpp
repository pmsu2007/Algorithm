/*
���� 1463��
1�� �����

1. X�� 3���� ������ ��������, 3���� ������.
2. X�� 2�� ������ ��������, 2�� ������.
3. 1�� ����.
�� �ּ� �� ����

10�� ��� 10 -> 9 -> 3 -> 1

DP
*/
#include <iostream>
#include <algorithm>

int save[1000001]; // index 1���� 1000000 ����

int DP(int x)
{
	save[1] = 0; // 1�� ���� X
	int a, b, c;

	// Bottom-Up ���
	for (int i = 2; i <= x; i++)
	{
		a = b = c = 1000001;

		// ��� ���� �õ�

		if (i % 3 == 0)
			a = save[i / 3] + 1;
		if (i % 2 == 0)
			b = save[i / 2] + 1;
		c = save[i - 1] + 1;

		save[i] = std::min({ a, b, c });
	}
	return save[x];
}

int main()
{
	int input;
	std::cin >> input;
	
	DP(input);

	std::cout << save[input] << '\n';
	return 0;
}
