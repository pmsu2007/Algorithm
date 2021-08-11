/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 
		만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 
		만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 
		만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

#include <iostream>
#include <string>

#define MAX_QUEUE_SIZE 10001


class Queue
{
	int* data;
	int rear; // 후단 삽입과 관련
	int fro; // 전단 삭제와 관련
public:
	Queue() {
		data = new int[MAX_QUEUE_SIZE];
		rear = fro = -1;
	}

	void push(int n)
	{
		data[++rear] = n;
	}

	int empty()
	{
		if (rear == fro)
			return 1;
		return 0;
	}

	int pop()
	{
		if (empty())
			return -1;
		else 
		{
			int item = data[++fro];
			return item;
		}
	}

	int size()
	{
		return rear - fro;
	}

	int front()
	{
		if (empty())
			return -1;
		else
		{
			int item = data[fro + 1];
			return item;
		}
	}

	int back()
	{
		if (empty())
			return -1;
		else
		{
			int item = data[rear];
			return item;
		}
	}
	~Queue() { delete[] data; }
};


int main()
{
	int test_case;
	std::cin >> test_case;

	Queue q;

	while (test_case--)
	{
		std::string s;
		std::cin >> s;

		if (!s.compare(std::string("push")))
		{
			int value;
			std::cin >> value;
			q.push(value);
		}
		else if (!s.compare(std::string("pop")))
		{
			std::cout << q.pop() << std::endl;
		}
		else if (!s.compare(std::string("empty")))
		{
			std::cout << q.empty() << std::endl;
		}
		else if (!s.compare(std::string("size")))
		{
			std::cout << q.size() << std::endl;
		}
		else if (!s.compare(std::string("front")))
		{
			std::cout << q.front() << std::endl;
		}
		else if (!s.compare(std::string("back")))
		{
			std::cout << q.back() << std::endl;
		}
	}

	return 0;

}