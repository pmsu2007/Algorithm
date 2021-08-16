/*
���� 1406��

������
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
�������� �ڵ��ϸ�
L : ���� ���ÿ��� pop �ϰ� �ٸ� �������� push
D : �ٸ� ���ÿ��� pop �ϰ� ���� �������� push
P x : ���� ���ÿ� push
B : ���� ���ÿ��� pop
*/
