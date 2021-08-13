/*
백준 2609번

최대공약수와 최소공배수
*/
#include <iostream>

int GCD(int a, int b)
{
	//재귀함수로 해결할 수 있다.
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
최대공약수(greatest common dibvisor):
최소공배수(largest common multiple)

lcm(a, b) = a*b/gcd(a, b)
*/