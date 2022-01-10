/*
¹éÁØ 2170¹ø
¼± ±ß±â
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> line;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int start, end;
	while (N--)
	{
		cin >> start >> end;
		line.push_back(make_pair(start, end));
	}

	sort(line.begin(), line.end());

	int left = -2e8; 
	int right = -2e8;
	int length = 0;

	for (int i = 0; i < line.size(); i++)
	{
		if (i == 0)
		{
			left = line[0].first;
			right = line[0].second;
		}
		else
		{
			if (right >= line[i].first) // °ãÄ¥ ¶§
			{
				right = max(right, line[i].second);
			}
			else // ¾È°ãÄ¥ ¶§
			{
				length += (right - left);
				left = line[i].first;
				right = line[i].second;
			}
		}
	}

	length += (right - left);

	cout << length;

}

/*
6
-1 6
1 3
2 5
3 5
6 7
6 8
*/
