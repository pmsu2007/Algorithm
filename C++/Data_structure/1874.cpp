/*
백준 1874
스택 수열
*/

#include <iostream>
#include <stack>
#include <vector>


void print_vector(std::vector<char>& v)
{
	for (const auto& elem : v) {
		std::cout << elem << '\n';
	}
}

int main()
{
	int test_case;
	std::cin >> test_case;

	std::vector<int> v;
	std::stack<int> s;

	for (int i = 0; i < test_case; i++)
	{
		int value;
		std::cin >> value;
		v.push_back(value);
	}

	std::vector<char> vc; // test_case * 2 만큼 출력

	int i = 1;
	int j = 0;

	while (j != test_case) {
		if (s.empty())
		{
			s.push(i);
			vc.push_back('+');

			if (i < test_case)
				i++;
		}
		else
		{
			if (v[j] != s.top())
			{
				s.push(i);
				vc.push_back('+');
				if (i < test_case)
					i++;
			}
			else
			{
				s.pop();
				vc.push_back('-');
				j++;
			}
		}
		
		if (s.size() > test_case)
			break;
	}

	if (j == test_case)
		print_vector(vc);
	else
		std::cout << "NO" << '\n';
}

/*
혹시 자신의 코드가 수열의 각 원소에 대해 지금까지 쌓아온 스택 전체를 순회해야 한다면 
시간 복잡도가 O(N^2)이 되어 시간 초과가 될 가능성이 높습니다. 
이 문제는 기본적으로 O(N)에 풀기를 원하는 문제입니다

std::endl; -> '\n' 으로 교체하닌까 해결 됨
*/