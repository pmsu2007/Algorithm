/*
백준 13975번
파일 합치기 3
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T;

int main()
{
	cin >> T;

	while (T--)
	{
		priority_queue<long long, vector<long long>, greater<long long>> pq;

		int K;
		cin >> K;

		for (int i = 0; i < K; i++)
		{
			int input;
			cin >> input;
			pq.push(input);
		}

		long long sum = 0;
		for (int i = 1; i <= K - 1; i++)
		{
			long long left = pq.top();
			pq.pop();
			long long right = pq.top();
			pq.pop();

			long long temp = left + right;
			pq.push(temp);
			sum += temp;
		}

		cout << sum << '\n';
	}
}