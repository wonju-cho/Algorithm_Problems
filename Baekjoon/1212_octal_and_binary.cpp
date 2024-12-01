#include<iostream>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//bit manipulation
	string numStr = ""; cin >> numStr;

	for (int i = 0; i < numStr.length(); i++)
	{
		int compare = 4;
		int num = numStr[i] - '0';

		if (numStr.length() == 1 && num == 0)
		{
			cout << 0;
			break;
		}

		bool flag = false;
		for (int j = 0; j < 3; j++, compare >>= 1)
		{
			if ((num & compare) != 0)
			{
				if (i == 0) flag = true;
				cout << 1;
			}
			else {
				if (i == 0 && !flag) continue;
				cout << 0;
			}
		}
	}

	//using array
	string numStr = ""; cin >> numStr;
	if (numStr.length() == 1 && numStr[0] == '0')
	{
		cout << 0;
		return 0;
	}

	string octal[8] = { "000","001","010", "011","100" ,"101","110","111" };
	for (int i = 0; i < numStr.length(); i++)
	{
		int num = numStr[i] - '0';
		if(i == 0)
		{
			bool flag = false;
			for(int o = 0; o < 3; o++)
			{
				if (!flag)
				{
					if(octal[num][o] != '0')
					{
						flag = true;
						cout << octal[num][o];
					}
				}
				else
				{
					cout << octal[num][o];
				}
			}
		}
		else
			cout << octal[num];
	}

}
