#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str = "";
	cin >> str;

	int alphabet[26] = {};

	for(int i = 0; i < str.length(); i++)
	{
		alphabet[str[i] - 'a']++;
	}

	for(int i = 0; i < 26; i++)
	{
		cout << alphabet[i] << " ";
	}

}

