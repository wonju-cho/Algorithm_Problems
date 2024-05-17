#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
unordered_map<char, int> dictionary;

void MakeDictionary() 
{
	char s = 'A'; int idx = 0;
	for (int i = 0; i < 26; i++, s++, idx++)
	{
		dictionary[s] = idx;
	}
	s = 'a';
	for (int i = 0; i < 26; i++, s++, idx++)
	{
		dictionary[s] = idx;
	}
	s = '0';
	for (int i = 0; i < 10; i++, s++, idx++)
	{
		dictionary[s] = idx;
	}
	dictionary['+'] = 62; dictionary['/'] = 63;
}

int GetNum(string str) {
	int res = 0; int compare = 1;
	for (int i = 7; i >= 0; i--)
	{
		if ((str[i] - '0' & 1) != 0)
			res += compare;
		
		compare <<= 1;
	}

	return res;
}

string Decoding(string str) 
{
	string temp = "";
	for (int i = 0; i < 4; i++)
	{
		int val = dictionary[str[i]];
		if ((val & 64) != 0)
		{
			val = val ^ 64;
		}
		if ((val & 128) != 0)
		{
			val = val ^ 128;
		}
		
		int compare = 32;
		for (int j = 0; j < 6; j++)
		{
			if((val&compare) != 0)
				temp += to_string(1);
			else
				temp += to_string(0);
			compare >>= 1;
		}
	}

	string res;
	res += GetNum(temp.substr(0, 8));
	res += GetNum(temp.substr(8, 8));
	res += GetNum(temp.substr(16));

	return res;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T = 0; cin >> T; 
	cin.ignore();

	//make dictionary
	MakeDictionary();
	
	for (int t = 1; t <= T; t++)
	{
		string str = ""; 
		getline(cin, str);
		int length = str.length();
		string temp = ""; string res = "";
		for (int i = 0; i < length; i++) 
		{
			if (i != 0 && i % 4 == 0)
			{
				res += Decoding(temp);
				temp = "";
			}
			temp += str[i];
		}

		res += Decoding(temp);

		cout << '#' << t << ' ' << res << "\n";
	}
    
    return 0;
}