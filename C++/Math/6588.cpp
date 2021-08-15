/*
백준 6588번
골드바흐의 추측

4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
*/

#include <iostream>
#include <cmath>
#include <vector>

bool Prime(int num)
{
	int a = static_cast<int>(sqrt(num));
		
	for (int i = 2; i <= a; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}


int main()
{

	int* arr = new int[1000000];

	for (int i = 2; i <= 1000000; i++) {
		arr[i] = i;
	}

	for (int i = 3; i <= 1000000; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= 1000000; j += i) { // i를 제외한 i의 배수들은 0으로 체크
			arr[j] = 0;
		}
	}

	while (true)
	{	
		int input;
		std::cin >> input;

		if (input != 0)
		{
			int a = 0, b = 0;
			int k = 0;
			for (int i = 2; i < 1000000; i++)
			{
				if (arr[i] != 0 && Prime(input - arr[i]))
				{
					a = arr[i];
					b = input - arr[i];
					std::cout << input << " = " << a << " + " << b << '\n';
					break;
				}
				k++;
			}

			if (k == 999998)
				std::cout << "Goldbach's conjecture is wrong" << '\n';
			
		}
		else
			return 0;
	}
}


/*

*/