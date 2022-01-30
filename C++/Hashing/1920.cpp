/*
백준 1920번
수 찾기
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct hash_map {

	vector<list<int>> data;

	int hash(int key)
	{
		if (key < 0)
			return (key * (-1)) / 10000;
		return key / 10000;
	}

public:
	hash_map()
	{
		data.resize(214748);
	}

	void insert(int value)
	{	
		int key = hash(value);
		data[key].push_back(value);
	}

	bool lookup(int value)
	{
		int key = hash(value);
		auto& entries = data[key];
		return find(entries.begin(), entries.end(), value) != entries.end();
	}
};

int main()
{
	int N;
	cin >> N;

	hash_map map;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		map.insert(input);
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int input;
		cin >> input;
		if (map.lookup(input))
			cout << 1 << '\n';
		else 
			cout << 0 << '\n';
	}
}