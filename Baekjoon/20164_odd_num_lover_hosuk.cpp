#include <iostream>
#include <string>

using namespace std;
int minimum = 999999;
int maximum = -1;

int CountOdd(string numStr)
{
	int res = 0;
	for(auto n: numStr)
	{
		if ((n - '0') % 2 == 1)
		{
			res++;
		}
	}
	return res;
}

void Divide(string str, int total)
{
	if (str.length() == 1) {
		total += (str[0] - '0') % 2 == 1 ? 1 : 0;
		minimum = min(minimum, total);
		maximum = max(maximum, total);
		return ;
	}
	else if(str.length() == 2)
	{
		total += CountOdd(str);
		Divide(to_string(str[0] - '0' + str[1] - '0'), total);
	}
	else
	{
		total += CountOdd(str);
		for (int i = 0; i < str.length(); i++)
		{
			for (int j = i + 1, k = 1; k < str.length() - i - 1; k++)
			{
				string parse1 = str.substr(0, j);
				string parse2 = str.substr(i + 1, k);
				string parse3 = str.substr(k + j);

				string temp = to_string(stoi(parse1) + stoi(parse2) + stoi(parse3));

				Divide(temp, total);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;  cin >> str;

	Divide(str, 0);

	cout << minimum << ' ' << maximum;
}