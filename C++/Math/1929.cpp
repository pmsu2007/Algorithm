/*
백준 1929번
소수 구하기
*/

#include<iostream>
#include<cmath>

bool Prime(int num)
{
	if (num < 2)
		return false;
	else if (num == 2)
		return true;
	else
	{
		int a = sqrt(num);
		for (int i = 2; i <= num/2 ; i++)
		{
			if (num % i == 0)
				return false;
		}
		return true;
	}
}


int main()
{
	int low, high;
	std::cin >> low >> high;

	for (int i = low; i <= high; i++)
	{
		if (Prime(i))
			std::cout << i << '\n';
	}
}

/* 

*/