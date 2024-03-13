#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	int m = 0;
	cin >> m;

	unordered_map<string, int> um1;
	unordered_map<string, int> um2;

	for(int i = 0; i < n; i++)
	{
		string temp = "";
		cin >> temp;

		um1[temp]++;
	}

	for(int i = 0 ; i < m; i++)
	{
		string temp = "";
		cin >> temp;

		um2[temp]++;
	}

	int cnt = 0;

	for(auto u2 : um2)
	{
		if(um1.count(u2.first))
		{
			cnt+=u2.second;
		}
	}

	cout << cnt;
}