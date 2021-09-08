/*
���� 1074��
Z
*/
#include <iostream>
#include <cmath>

int e_row, e_col;

int section(int num)
{
	int size = std::pow(2, num);
	if ((0 <= e_row) && (0 <= e_col) && (e_row < size / 2) && (e_col < size / 2))
		return 1;
	else if ((0 <= e_row) && (size / 2 <= e_col) && (e_row < size / 2) && (e_col < size))
		return 2;
	else if ((size / 2 <= e_row) && (0 <= e_col) && (e_row < size) && (e_col < size / 2))
		return 3;
	else
		return 4;
}

int divide(int size)
{
	int temp = std::pow(2, size - 1);
	int block = std::pow(temp, 2);
	if (size == 0)
		return 0;
	
	switch (section(size))
	{
	case 1:
	{
		return divide(size - 1);
	}
	case 2:
	{	e_col -= std::pow(2, size) / 2;
		return block + divide(size - 1);
	}
	case 3:
	{
		e_row -= std::pow(2, size) / 2;
		return 2*block + divide(size - 1);
	}
	case 4:
	{
		e_col -= std::pow(2, size) / 2;
		e_row -= std::pow(2, size) / 2;
		return 3*block + divide(size - 1);
	}
	}
}


int main()
{
	int num;
	std::cin >> num >> e_row >> e_col;

	std::cout << divide(num);
}

/*
e_row & e_col �� ��ġ�� ��и鸸 
O(N) -> O(logN) 


1 ��и� �״��
2 ��и� col --
3 ��и� row --
4 ��и� col, row --

1. size�� 0�� �� �� ���� ������ ��и��� ã�´�
2. �ܰ躰�� ��и� ���� ���� cnt�� ���Ѵ�
*/