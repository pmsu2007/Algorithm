/*
백준 2004번
조합 0의 개수
*/

#include <iostream>

int divide_five(int number)
{
	int num = 0;
	for (int i = 5; i <= number; i *= 5)
		num += number / i;
	return num;
}

int divide_two(int number)
{
	int num = 0;
	for (int i = 2; i <= number; i *= 2)
		num += number / i;
	return num;
}


int main()
{
	int n, m;
	std::cin >> n >> m;
	int ans = std::min((divide_five(n) - divide_five(m) - divide_five(n - m))
		, (divide_two(n) - divide_two(m) - divide_two(n - m)));

	std::cout << ans;
}