/*
백준 2447번
별 찍기 - 10
*/

#include <iostream>

char star[7000][7000] = {'c',};

void printStar(int x, int y)
{
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			if ((i % 3 == 1) && (j % 3 == 1))
				star[i][j] = ' ';
			else
				star[i][j] = '*';			
		}
	}
	
}

void divide(int n, int x, int y)
{
	if (n == 3)
	{
		printStar(x, y);
	}
	else
	{
		int gap = n / 3;
		/*
		divide(gap, x, y); // 1
		divide(gap, x + gap, y); // 2
		divide(gap, x + gap * 2, y); // 3
		divide(gap, x, y + gap); // 4  
		divide(gap, x + gap * 2, y + gap); // 6
		divide(gap, x, y + gap * 2); // 7
		divide(gap, x + gap, y + gap * 2); // 8
		divide(gap, x + gap * 2, y + gap * 2); // 9
		*/
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 1 && j == 1)
					;
				else
					divide(gap, x + (i * gap), y + (j * gap));
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			star[x][y] = ' ';
		}
	}

	divide(N, 0, 0);

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			std::cout << star[x][y];
		}
		std::cout << '\n';
	}
}

/*

*/