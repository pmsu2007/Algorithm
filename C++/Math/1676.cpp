/*
백준 1676번
팩토리얼 0의 개수

10으로 나누었을 때 나머지 없으면 됨
*/

#include <iostream>

int main() 
{
	int num;
	std::cin >> num;
	
	int arr[2] = { 0, 0 };

	for (int i = 2; i <= num; i++)
	{
		int j = i;
		while (j > 0) {
			if (j % 5 == 0)
			{
				arr[1]++;
				j = j / 5;
			}
			else if (j % 2 == 0)
			{
				arr[0]++;
				j = j / 2;
			}
			else
				break;
		}
	}

	int count = std::min(arr[0], arr[1]); 
	std::cout << count << '\n';
}

/*
각 i 당 소인수 분해 해서 배열에 저장 
2랑 5 중 최소 값이 0의 갯수
*/