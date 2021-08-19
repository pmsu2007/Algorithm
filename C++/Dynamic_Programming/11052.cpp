/*
백준 11052번
카드 구매하기
*/

#include <iostream>
#include <vector>
#include <algorithm>

int memo[1001];

int DP(int x, std::vector<int>& v)
{
	memo[1] = v[1]; 

	for (int i = 2; i <= x; i++)
	{
		std::vector<int> comp; // 비교 개수 증가로 인한 vector 사용

		for (int j = 0; j <= i / 2; j++)
		{
			comp.push_back(v[j] + v[i - j]);
		}
		v[i] = *max_element(comp.begin(), comp.end());
		memo[i] = v[i]; // i의 최대값 갱신
		comp.clear();
	}

	return memo[x];
}

int main()
{
	int test_case;
	std::cin >> test_case;

	std::vector<int> v;
	v.push_back(0); // 0을 더할 때 

	for (int i = 0; i < test_case; i++)
	{
		int input;
		std::cin >> input;
		v.push_back(input);
	}

	DP(test_case, v);

	std::cout << memo[test_case];
	return 0;
}

/*
test_case를 만들 수 있는 모든 케이스 중 최대 값

test_case : 2 -> 2
0 2
1 1
test_case : 3 -> 3
0 3
1 2

test_case : 4 -> 5
0 4
1 3
2 2 

위의 경우만 생각하면 된다
*/