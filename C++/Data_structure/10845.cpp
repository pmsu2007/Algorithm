/*
push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. 
		���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. 
		���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. 
		���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/

#include <iostream>
#include <string>

#define MAX_QUEUE_SIZE 10001


class Queue
{
	int* data;
	int rear; // �Ĵ� ���԰� ����
	int fro; // ���� ������ ����
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