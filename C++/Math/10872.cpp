/*
백준 10872번
팩토리얼
*/

#include <iostream>

int factorial(int num)
{
	if (num == 0)
		return 1;
	else if (num == 1)
		return 1;
	else
		return num * factorial(num - 1);
}


int main()
{
	int num;
	std::cin >> num;
	
	int fact = factorial(num);
	std::cout << fact << '\n';
	
	return 0;
}