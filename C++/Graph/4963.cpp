/*
백준 4963번
섬의 개수
*/

#include <iostream>
#include <vector>

using namespace std;

int width, height;
vector<vector<int>> map (50, vector<int>(50));
int direction[] = { -1, 0, 1 };

bool dfs(int row, int col) {

	/*for (int a = 0; a < height; a++)
	{
		for (int b = 0; b < width; b++)
		{
			cout << map[a][b] << " ";
		}
		cout << '\n';
	}
	cout << '\n';*/

	if (row < 0 || col < 0 || row >= height|| col >= width)
		return false;
	else if (map[row][col] == 1)
	{
		map[row][col] = 2;// 방문 처리
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i % 3 == 1 && j % 3 == 1)
					continue;
				dfs(row + direction[j], col +direction[i]);
			}
		}
		return true;
	}
	return false;
}

int main()
{
	while (true)
	{
		cin >> width >> height;
		
		if (width == 0 && height == 0) // 종료 조건
			break;

		bool existIsland = false;

		for (int i = 0; i < height; i++) // 지도 입력
		{
			for (int j = 0; j < width; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 1)
					existIsland = true;
			}
		}

		if (!existIsland) // 섬이 없을 경우
		{
			cout << 0 << '\n';
			continue;
		}
		
		//dfs
		int count = 0;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (dfs(i, j))
					count++;
			}
		}

		cout << count << '\n';
	}
}