/*
���� 1934��
�ּҰ����
*/

#include <iostream>

int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main()
{
	int test_case;
	std::cin >> test_case;

	int a, b;

	while (test_case--)
	{	
		std::cin >> a >> b;
		int gcd = GCD(a, b);
		int lcm = a * b / gcd;
		std::cout << lcm << '\n';
	}
}
