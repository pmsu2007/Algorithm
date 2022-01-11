/*
���� 1461��
������
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int N, M;

vector<int> booklist;

int main()
{
	cin >> N >> M;

	if (N == 1)
	{
		int input;
		cin >> input;
		cout << abs(input);
	}
	else
	{
		int input;
		int left, right;
		left = right = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> input;
			if (input < 0)
				left++;
			else
				right++;

			booklist.push_back(input);
		}

		sort(booklist.begin(), booklist.end());

		int ans = 0;

		// ��� ���� �� �ָ� ���� ��
		if (abs(booklist[0]) < abs(booklist[booklist.size() - 1]))  
		{
			// ���� ����
			for (int i = 0; i < left; i += M)
			{
				ans += abs(booklist[i]) * 2;
			}

			// ��� ����
			for (int i = booklist.size() - 1 ; i >= left; i -= M)
			{
				if (i == booklist.size() - 1)
					ans += booklist[booklist.size() - 1];
				else
					ans += abs(booklist[i]) * 2;
			}
		}
		// ���� ���� �� �ָ� ���� ��
		else
		{
			// ��� ����
			for (int i = booklist.size() - 1; i >= left; i -= M)
			{
				ans += abs(booklist[i]) * 2;
			}

			// ���� ����
			for (int i = 0; i < left; i += M)
			{
				if (i == 0)
					ans += abs(booklist[0]);
				else
					ans += abs(booklist[i]) * 2;
			}
		}

		cout << ans;
	}
}