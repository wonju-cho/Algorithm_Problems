#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool ContactCheck(pair<int, int> p1, pair<int, int> p2)
{
	int distance = sqrt(pow(p1.first - p2.first, 2));

	if (p1.second + p2.second < distance || abs(p1.second - p2.second) > distance)
		return false;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	//x, r
	vector<pair<int, int>> vec;

	for(int i = 0; i < n; i++)
	{
		int x = 0;
		int r = 0;
		cin >> x;
		cin >> r;
		vec.push_back({ x, r });
	}

	sort(vec.begin(), vec.end());

	//x, r
	stack<pair<int, int>> stk;
	stk.push({ 0,0 });
	for(int i = 0; i < n; i++)
	{
		if(!ContactCheck(stk.top(), vec[i]))
		{
			stk.push(vec[i]);
		}
		else
		{
			cout<<"NO";
			return 0;
		}
	}

	cout<<"YES";
}
