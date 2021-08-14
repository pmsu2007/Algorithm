/*
백준 1978번
소수 찾기
*/

#include <iostream>

int main(){
	int N;
	std::cin >> N;

	int count = 0;

	while (N--)
	{
		int input;
		std::cin >> input;
		if (input != 1)
		{
			if (input == 2)
				count++;
			else
			{
				int k = 0;
				for (int i = 2; i < input; i++)
				{
					if (input % i == 0)
					{
						k++;
						break;
					}
				}
				if (k == 0)
					count++;
			}
		}
	}
	std::cout << count << '\n';
}