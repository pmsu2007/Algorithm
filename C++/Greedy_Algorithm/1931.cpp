/*
백준 1931번
회의실 배정
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first; // 오름차순 정렬

	return a.second < b.second; // 오름차순 정렬
}


int main()
{
	int N;
	cin >> N;

	int count = 1;
	vector<pair<int, int>> time;

	int start, end;
	for (int j = 0; j < N; j++)
	{			
		cin >> start >> end;
		time.push_back({ start, end }); 
	}
	// end 를 오름차순으로 정렬
	sort(time.begin(), time.end(), compare);
	
	for (auto i : time)
		cout << i.first << " " << i.second << '\n';

	int end_time = time[0].second;
	for (int i = 1; i < N; i++)
	{
		if (end_time <= time[i].first)
		{
			end_time = time[i].second;
			count++;
		}
	}

	cout << count;
}

/*
4
1 2
2 4
2 3
3 5

6
1 2
2 4
3 4
2 3
4 6
3 5



*/