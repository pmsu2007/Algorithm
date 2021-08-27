/*
백준 1476번
날짜 계산
E : 1 ~ 15
S : 1 ~ 28
M : 1 ~ 19
*/

#include <iostream>

int main()
{
	int E, S, M;
	std::cin >> E >> S >> M;

	int year = 0;
	int earth = 0;
	int sun = 0;
	int moon = 0;
	while (true)
	{
		year++;
		earth++;
		sun++;
		moon++;
		
		if (earth % 16 == 0)
			earth = 1;
		if (sun % 29 == 0)
			sun = 1;
		if (moon % 20 == 0)
			moon = 1;

		if (E == earth && S == sun && M == moon)
		{
			std::cout << year;
			break;
		}
	}
}