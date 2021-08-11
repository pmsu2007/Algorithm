#pragma warning(disable:4996)

#include <iostream>
#include <string>
#include <cstring>
#include <stack>

#define MAX_STACK_SIZE 20



void reverse_print(std::stack<char>& s, char* ptr)
{
	int len = strlen(ptr);

	for (int i = 0; i < len; i++)
	{
		s.push(ptr[i]);
	}

	for (int i = 0; i < len; i++)
	{
		std::cout << s.top();
		s.pop();
	}
	std::cout << " ";
}


int main()
{
	int test_case;

	std::cin >> test_case;
	std::cin.ignore(1, '\n');

	for (int i = 0; i < test_case; i++)
	{
		char buffer[1000];
		std::cin.getline(buffer, 1000, '\n');

		char* ptr = strtok(buffer, " ");

		std::stack<char> s;

		while (ptr != NULL)
		{
			reverse_print(s, ptr);
			ptr = strtok(NULL, " ");
		}
		std::cout << std::endl;
	}
}

/*
getline�� �̿��� ��, \n�� �Է¹��ۿ� �����ϸ� �Է��� ���������.
����, cin.ignore �� ���۸� ��������.
*/


/*
strtok ������� : <cstring>

strtok �Լ�����
char* strtok(char* str, char* delimiters);


strtok �Լ��� ó�� �ҷ��ٶ��� ���ϴ� ���ڿ��� ����ְ� �� �������ʹ�
ù��° ���ڿ� NULL�� �־��ش�.

strtok �� NULL�� ��ȯ�� �� ���� ��� �ҷ��־�� �Ѵ�.
*/