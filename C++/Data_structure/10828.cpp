/*
 정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오

 명령은 다음과 같다

 push
 pop
 size
 empty
 top

*/
#define MAX_STACK_SIZE 10000

class Stack {
	int tp;
	int* data;
public:
	Stack() {
		data = new int[MAX_STACK_SIZE];
		tp = -1;
	}

	void push(int n)
	{
		data[++tp] = n;
	}

	int pop()
	{
		if (tp <= -1)
		{
			return -1;
		}
		return data[tp--];
	}

	int size()
	{
		return tp + 1;
	}

	int empty()
	{
		if (tp == -1)
			return 1;
		else
			return 0;
	}

	int top()
	{
		if (tp == -1)
			return -1;
		return data[tp];
	}

	~Stack() { delete[] data; }
};

#include <iostream>
#include <string>

int main()
{
	Stack stack;
	int test_case;

	std::cin >> test_case;
	int i = 0;

	std::string command1;

	while (i < test_case)
	{
		std::cin >> command1;

		if (!command1.compare(std::string("push")))
		{
			int value;
			std::cin >> value;
			stack.push(value);
		}

		if (!command1.compare(std::string("pop")))
		{
			std::cout << stack.pop() << std::endl;
		}

		if (!command1.compare(std::string("size")))
		{
			std::cout << stack.size() << std::endl;
		}

		if (!command1.compare(std::string("empty")))
		{
			std::cout << stack.empty() << std::endl;
		}

		if (!command1.compare(std::string("top")))
		{
			std::cout << stack.top() << std::endl;
		}
		i++;
	}
	return 0;
}