/*
���� 2609��

�ִ������� �ּҰ����
*/
#include <iostream>

int GCD(int a, int b)
{
	//����Լ��� �ذ��� �� �ִ�.
	if (b == 0)
		return a;
	return GCD(b, a % b);
	
}

int LCM(int a, int b)
{
	return a * b / GCD(a, b);
}

int main()
{
	int A, B;

	std::cin >> A >> B;

	int gcd = GCD(A, B);
	int lcm = LCM(A, B);

	std::cout << gcd << '\n';
	std::cout << lcm << '\n';

	return 0;
}

/*
�ִ�����(greatest common dibvisor):
�ּҰ����(largest common multiple)

lcm(a, b) = a*b/gcd(a, b)
*/