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
		std::cout << elem << std::endl;
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

	while (vc.size() != test_case * 2) {
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
		std::cout << "NO" << std::endl;
}

