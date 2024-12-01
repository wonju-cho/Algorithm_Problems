#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	getline(cin, str);
	bool isTagStr = false;
	string temp = "";

	for(int i = 0; i < str.length(); i++)
	{
		if (str[i] == '<') isTagStr = true;

		if(isTagStr)
		{
			int size = temp.size();
			for (int j = size - 1; j >= 0; j--)
			{
				cout << temp[j];
			}
			temp.clear();

			if (str[i] == '>')
			{
				isTagStr = false;
			}
			cout << str[i];
		}
		else if(str[i] == ' ' && !isTagStr)
		{
			int size = temp.size();
			for (int j = size - 1; j >= 0; j--)
			{
				cout << temp[j];
			}
			temp.clear();
			cout << ' ';
		}
		else
		{
			temp += str[i];
		}
	}

	if(!temp.empty())
	{
		int size = temp.size();
		for (int j = size - 1; j >= 0; j--)
		{
			cout << temp[j];
		}
	}
}
