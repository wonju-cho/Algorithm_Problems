#include <iostream>
#include <cmath>
#include <unordered_map>
#include <string>

using namespace std;
struct Key
{
	bool isVowel;
	pair<int, int> point;
};

unordered_map<char, Key> keyUMap;
char keys[26] = { 'q','w','e','r','t','y','u','i','o','p','a','s','d','f',
'g','h','j','k','l','z','x','c','v','b','n','m' };

void SetKeyboard()
{
	//5,5,4
	pair<int, int> width[3] = { {10, 5}, {19, 5}, {26,4} };
	int widthIdx = 0;
	int idx = 0;
	for(int i = 0; i < 26; i++, idx++)
	{
		if (i == width[widthIdx].first)
		{
			widthIdx++;
			idx = 0;
		}
		bool isVowel = idx < width[widthIdx].second ? false : true;
		keyUMap[keys[i]] = { {isVowel}, {widthIdx, idx} };
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char sL; char sR; cin >> sL; cin >> sR;
	string str; cin >> str;
	int time = 0;

	SetKeyboard();

	for (int i = 0; i < str.length(); i++)
	{
		//자음: 왼쪽
		if(!keyUMap[str[i]].isVowel)
		{
			const int distance = abs(keyUMap[sL].point.first - keyUMap[str[i]].point.first) + abs(keyUMap[sL].point.second - keyUMap[str[i]].point.second);
			time += distance;
			sL = str[i];
		}
		else
		{
			const int distance = abs(keyUMap[sR].point.first - keyUMap[str[i]].point.first) + abs(keyUMap[sR].point.second - keyUMap[str[i]].point.second);
			time += distance;
			sR = str[i];
		}
		time += 1;
	}

	cout << time;
}
