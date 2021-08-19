/*
백준 1463번
1로 만들기

1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
2. X가 2로 나누어 떨어지면, 2로 나눈다.
3. 1을 뺀다.
중 최소 값 선택

10의 경우 10 -> 9 -> 3 -> 1

DP
*/
#include <iostream>
#include <algorithm>

int save[1000001]; // index 1부터 1000000 까지

int DP(int x)
{
	save[1] = 0; // 1은 연산 X
	int a, b, c;

	// Bottom-Up 방식
	for (int i = 2; i <= x; i++)
	{
		a = b = c = 1000001;

		// 모든 연산 시도

		if (i % 3 == 0)
			a = save[i / 3] + 1;
		if (i % 2 == 0)
			b = save[i / 2] + 1;
		c = save[i - 1] + 1;

		save[i] = std::min({ a, b, c });
	}
	return save[x];
}

int main()
{
	int input;
	std::cin >> input;
	
	DP(input);

	std::cout << save[input] << '\n';
	return 0;
}
