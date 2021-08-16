/*
백준 1406번

에디터
*/


#include <iostream>
#include <string>
#include <deque>
#include <vector>


int main()
{	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie();

	std::string s;
	std::cin >> s;
	
	std::deque<char> base;
	std::deque<char> sub;

	for (int i = 0; i < s.size(); i++)
	{
		base.push_back(s[i]);
	}

	int test_case;
	std::cin >> test_case;

	while (test_case--)
	{
		std::string command;
		std::cin >> command;

		if (!command.compare(std::string("P")))
		{
			char input;
			std::cin >> input;
			base.push_back(input);
		}
		else if (!command.compare(std::string("L")))
		{
			if (!base.empty())
			{
				char temp = base.back();
				base.pop_back();
				sub.push_front(temp);
			}
		}
		else if (!command.compare(std::string("D")))
		{
			if (!sub.empty())
			{
				char temp = sub.front();
				sub.pop_front();
				base.push_back(temp);
			}
		}
		else if (!command.compare(std::string("B")))
		{
			if (!base.empty())
			{
				base.pop_back();
			}
		}
	}
	if (!base.empty())
	{
		for (auto i = base.begin(); i != base.end(); i++)
			std::cout << *i;
	}

	if (!sub.empty())
	{
		for (auto i = sub.begin(); i != sub.end(); i++)
			std::cout << *i;
	}
}

/*
스택으로 코딩하면
L : 기존 스택에서 pop 하고 다른 스택으로 push
D : 다른 스택에서 pop 하고 기존 스택으로 push
P x : 기존 스택에 push
B : 기존 스택에서 pop
*/
