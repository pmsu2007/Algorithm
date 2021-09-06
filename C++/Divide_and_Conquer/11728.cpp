#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	
	std::vector<int> origin;

	int input;
	while (N--)
	{
		std::cin >> input;
		origin.push_back(input);
	}

	while (M--)
	{
		std::cin >> input;
		origin.push_back(input);
	}

	std::sort(origin.begin(), origin.end());

	for (auto i : origin)
	{
		std::cout << i << " ";
	}
}