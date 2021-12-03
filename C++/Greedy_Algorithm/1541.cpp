/*
น้มุ 1541น๘
ภาพ๎น๖ธฐ ฐýศฃ
*/

#include <iostream>
#include <string>

using namespace std;



int main()
{
	string formula;
	cin >> formula;

	int ans = 0;
	bool minus = false;
	string num;

	for (int i = 0; i <= formula.size(); i++)
	{
		if (formula[i] == '-' || formula[i] == '+' || i == formula.size())
		{
			if (minus)
			{
				ans -= stoi(num);
				num = "";
			}
			else
			{
				ans += stoi(num);
				num = "";
			}
		}
		else 
		{
			num += formula[i];
		}

		if (formula[i] == '-')
			minus = true;
	}

	cout << ans;
}


/*
55-50+40
-55-50-40
*/