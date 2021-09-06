/*
백준 11729벉
하노이 탑 이동 순서
*/
#include <iostream>

int DP[21];

void count(int num)
{
	DP[1] = 1;
	for (int i = 2; i <= num; i++)
	{
		DP[i] = 2 * DP[i - 1] + 1;
	}
}

void move(int num, int start, int end)
{
	std::cout << start << " " << end << '\n';
}
void hanoi(int num, int start, int end, int via)
{
	if (num == 1)
	{
		move(1, start, end);
	}
	else
	{
		hanoi(num - 1, start, via, end);
		move(num, start, end);
		hanoi(num - 1, via, end, start);
	}
}
int main()
{
	int num;
	std::cin >> num;
	count(num);
	std::cout << DP[num] << '\n';
	hanoi(num, 1, 3, 2);
}

/*

hanoi (5, 1, 3, 2)
= hanoi (4, 1, 2, 3) + hanoi (1, 1, 3, 2) + hanoi (4, 2, 3, 1)

hanoi(3, 1, 3, 2)
= hanoi(2, 1, 2, 3) + hanoi (1, 1, 3, 2) + hanoi(2, 2, 3, 1)

*/