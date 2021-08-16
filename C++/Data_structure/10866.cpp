/*
���� 10866��
��

push_front X: ���� X�� ���� �տ� �ִ´�.
push_back X: ���� X�� ���� �ڿ� �ִ´�.
pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���� ����ִ� ������ ������ ����Ѵ�.
empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/

#include <iostream>
#include <string>
#include <deque>



int main()
{
	int test_case;
	std::cin >> test_case;

	std::deque<int> dq;

	while (test_case--)
	{
		std::string command;
		std::cin >> command;

		if (!command.compare(std::string("push_back")))
		{
			int input;
			std::cin >> input;
			dq.push_back(input);
		}
		else if (!command.compare(std::string("push_front")))
		{
			int input;
			std::cin >> input;
			dq.push_front(input);
		}
		else if (!command.compare(std::string("pop_front")))
		{
			if (dq.empty())
				std::cout << -1 << '\n';
			else {
				int value = dq.front();
				dq.pop_front();
				std::cout << value << '\n';
			}
		}
		else if (!command.compare(std::string("pop_back")))
		{
			if (dq.empty())
				std::cout << -1 << '\n';
			else {
				int value = dq.back();
				dq.pop_back();
				std::cout << value << '\n';
			}
		}
		else if (!command.compare(std::string("size")))
		{
			std::cout << dq.size() << '\n';
		}
		else if (!command.compare(std::string("empty")))
		{
			std::cout << dq.empty() << '\n';
		}
		else if (!command.compare(std::string("front")))
		{
			if (dq.empty())
				std::cout << -1 << '\n';
			else
				std::cout << dq.front() << '\n';
		}
		else if (!command.compare(std::string("back")))
		{
			if (dq.empty())
				std::cout << -1 << '\n';
			else
				std::cout << dq.back() << '\n';
		}
	}
	return 0;
}