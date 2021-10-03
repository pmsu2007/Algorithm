/*
백준 2630번
색종이 만들기
*/

#include <iostream>
#include <vector>

using namespace std;

int white = 0;
int blue = 0;

std::vector<vector<int>> paper(128, vector<int>(128));

bool check(int x, int y, int size)
{
	int compare = paper[x][y];

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (compare != paper[i][j])
				return false;
		}
	}

	return true;
}

void divide(int x, int y, int size)
{
	if (!check(x, y, size))
	{
		int gap = size / 2;
		divide(x, y, gap);
		divide(x + gap, y, gap);
		divide(x, y + gap, gap);
		divide(x + gap, y + gap, gap);
	}
	else
	{
		if (paper[x][y] == 1) // color check
			blue++;
		else
			white++;
	}
}


int main()
{
	int size;
	cin >> size;

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			cin >> paper[x][y];
		}
	}

	divide(0, 0, size);

	cout << white << '\n' << blue;
}