/*
���� 11047��
���� 0
*/

#include <iostream>
#include <algorithm>

using namespace std;

int coin[11];
int main()
{
	int N, K;
	cin >> N >> K;

	for (int i = N - 1; i >= 0; i--)
	{
		cin >> coin[i]; // ��������
	}
	// index ã��
	int index = 0;
	while (index != N - 1)
	{
		if (K > coin[index])
			break;
		index++;
	}

	int count = 0;

	while (K != 0)
	{
		count += K / coin[index];
		K %= coin[index++];
	}
	
	cout << count;

}