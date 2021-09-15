/*
백준 11047번
동전 0
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
		cin >> coin[i]; // 내림차순
	}
	// index 찾기
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