/*
백준 1158
요세푸스 문제
*/
#include <iostream>
#include <queue>
#include <vector>

void print(std::vector<int>& v)
{
	auto i = v.begin();
	std::cout << "<" << *i;
	for (auto i = v.begin() + 1; i != v.end(); i++)
	{
		std::cout <<", "<< *i ;
	}
	std::cout << ">";
}

int main()
{
	int n, k;
	std::cin >> n >> k;

	std::queue<int> q;

	// 큐에 1부터 n까지 저장
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	
	std::vector<int> v;

	int count = 1;

	while (!q.empty())
	{
		int value = q.front();
		
		if (count % k != 0)
		{
			q.pop();
			q.push(value);
		}
		else
		{
			q.pop();
			v.push_back(value);
		}
		count++;
	}
	print(v);

	return 0;
}

/*
큐를 이용해서 해결
*/