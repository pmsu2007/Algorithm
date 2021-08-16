/*
백준 10866번
덱

push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
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