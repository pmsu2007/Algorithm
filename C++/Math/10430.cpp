/*
백준 10430번

나머지
*/
#include <iostream>

int main()
{
	int A, B, C;

	std::cin >> A >> B >> C;

	std::cout << (A + B) % C << '\n';
	std::cout << ((A % C) + (B % C)) % C << '\n';
	std::cout << (A * B) % C << '\n';
	std::cout << ((A % C) * (B % C)) % C << '\n';

	return 0;
}