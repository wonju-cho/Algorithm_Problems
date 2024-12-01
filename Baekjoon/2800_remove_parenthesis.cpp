#include <iostream>
#include <stack>
#include <set>
#include <vector>

using namespace std;

set<string> res;
string expression;
bool arr[101];
bool visited[101];
vector<pair<int, int>> vii;

void DFS(int idx, int cnt)
{
	if (cnt >= 1)
	{
		string temp = "";
		for (int i = 0; i < expression.length(); i++)
		{
			if (!arr[i])
			{
				temp += expression[i];
			}
		}
		res.insert(temp);
	}

	for (int i = idx; i < vii.size(); i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		arr[vii[i].first] = true;
		arr[vii[i].second] = true;
		DFS(idx + 1, cnt + 1);
		visited[i] = false;
		arr[vii[i].first] = false;
		arr[vii[i].second] = false;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	expression = str;

	stack<int> stk;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			stk.push(i);
		}
		else if (str[i] == ')')
		{
			vii.push_back({ stk.top(), i });
			stk.pop();
		}
	}

	DFS(0, 0);

	for (auto s : res)
	{
		cout << s << "\n";
	}

}