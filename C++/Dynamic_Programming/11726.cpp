/*
���� 11726��
2*n Ÿ�ϸ�
*/
#include <iostream>

int memo[1001];

int DP(int x)
{
	memo[1] = 1;
	memo[2] = 2;
	for (int i = 3; i <= x; i++)
	{
		memo[i] = (memo[i - 1] + memo[i - 2]) % 10007;
	}

	return memo[x];
}

int main()
{
	int x;
	std::cin >> x;

	DP(x);

	std::cout << memo[x];
}
/*
�Ǻ���ġ ����
���ʿ� 1*2 : �����ʿ� (n-1)*2 
���ʿ� 2*1 : �����ʿ� (n-2)*2
*/