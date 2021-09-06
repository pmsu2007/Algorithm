/*
백준 1780번
종이의 개수
*/

#include <iostream>

int matrix[3000][3000];
int ans[3] = { 0,0,0 };

void divideMatrix(int row, int col, int size)
{
	std::cout << "size: " << size <<'\n';
	std::cout << "row: " << row << " col: " << col << '\n';
	int temp = matrix[row][col];
	if (size == 1)
	{
		if (temp == -1)
			ans[0]++;
		else if (temp == 0)
			ans[1]++;
		else
			ans[2]++;
	}
	else
	{
		bool exit = false;
		for (int i = row; i < row + size; i++)
		{
			for (int j = col; j < col + size; j++)
			{
				if (matrix[i][j] != temp)
				{
					int gap = size / 3;
					divideMatrix(row, col, gap);
					divideMatrix(row, col + gap, gap);
					divideMatrix(row, col + gap * 2, gap);
					divideMatrix(row + gap, col, gap);
					divideMatrix(row + gap, col + gap, gap);
					divideMatrix(row + gap, col + gap * 2, gap);
					divideMatrix(row + gap * 2, col, gap);
					divideMatrix(row + gap * 2, col + gap, gap);
					divideMatrix(row + gap * 2, col + gap * 2, gap);
					exit = true;
					break;
				}
			}
			if (exit)
				break;
		}
		if (!exit)
		{
			if (temp == -1)
				ans[0]++;
			else if (temp == 0)
				ans[1]++;
			else
				ans[2]++;
		}
	}
}

int main()
{
	int size;
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	divideMatrix(0, 0, size);

	for (auto i : ans)
		std::cout << i << '\n';
}

/*

1. 분할
*/