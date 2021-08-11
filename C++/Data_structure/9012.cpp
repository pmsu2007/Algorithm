/*
괄호 문자열 (PS)
Valid PS 인지 판별하고, 결과를 YES와 NO로 나타내라
'(' 이랑 ')' 이 짝이 맞아야 됨. ')' '(' 은 안됨

'(' 를 발견하면 스택에 push, ')'를 발견하면 스택에서 pop하고 '('이 나와야 됨.
*/

#include <iostream>
#include <cstring>
#include <stack>

int main()
{
	int test_case;

	std::cin >> test_case;

	while (test_case--)
	{
		char buffer[51]; // 문자길이 2 이상 50이하
		std::cin >> buffer;

		std::stack<char> s;

		int len = strlen(buffer);
		int size = 0; // 마지막에 ')' 나오는거 방지
		for (int i = 0; i < len; i++)
		{
			if (buffer[i] == '(')
			{
				s.push(buffer[i]);
				size++;
			}
			else if (buffer[i] == ')')
			{
				if (s.empty())
				{
					size--;
					break;
				}
				else
				{
					s.pop();
					size--;
				}
			}
		}

		if (s.size() == 0 && size == 0)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}
	return 0;
}

/*
표준 출력을 사용한다 ?
C++
헤더파일 : <iostream>
표준입력 : std::cin
표준출력 : std::cout
개행 : std::endl; , '\n'
*/