/*
백준 1934번
최소공배수
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

/*
두 자연수 A, B에 대해서 A의 배수이면서 B의 배수인 자연수를 A와 B의 공배수라고 한다.
*/