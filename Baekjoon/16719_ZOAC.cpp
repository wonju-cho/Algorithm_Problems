#include <iostream>
#include <string>

using namespace std;
string input;
string res;
int len;
bool v[100];

void Recursion(int s, int e)
{
	if (s >= e) return;
	char temp = input[s]; int idx = s;
	for(int i = s; i < e; i++)
	{
		if(temp > input[i])
		{
			temp = input[i];
			idx = i;
		}
	}

	v[idx] = true;

	string res = "";
	for(int i = 0; i < len; i++)
	{
		if (v[i])
			res += input[i];
	}
	cout << res << "\n";

	Recursion(idx + 1, e);
	Recursion(s, idx);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> input;
	len = input.length();

	Recursion(0, len);
}