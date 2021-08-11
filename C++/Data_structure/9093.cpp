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
getline을 이용할 때, \n이 입력버퍼에 존재하면 입력을 끊어버린다.
따라서, cin.ignore 로 버퍼를 지워주자.
*/


/*
strtok 헤더파일 : <cstring>

strtok 함수정의
char* strtok(char* str, char* delimiters);


strtok 함수를 처음 불러줄때만 원하는 문자열을 집어넣고 그 다음부터는
첫번째 인자에 NULL을 넣어준다.

strtok 가 NULL을 반환할 때 까지 계속 불러주어야 한다.
*/