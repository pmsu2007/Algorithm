/*
��ȣ ���ڿ� (PS)
Valid PS ���� �Ǻ��ϰ�, ����� YES�� NO�� ��Ÿ����
'(' �̶� ')' �� ¦�� �¾ƾ� ��. ')' '(' �� �ȵ�

'(' �� �߰��ϸ� ���ÿ� push, ')'�� �߰��ϸ� ���ÿ��� pop�ϰ� '('�� ���;� ��.
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
		char buffer[51]; // ���ڱ��� 2 �̻� 50����
		std::cin >> buffer;

		std::stack<char> s;

		int len = strlen(buffer);
		int size = 0; // �������� ')' �����°� ����
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
ǥ�� ����� ����Ѵ� ?
C++
������� : <iostream>
ǥ���Է� : std::cin
ǥ����� : std::cout
���� : std::endl; , '\n'
*/