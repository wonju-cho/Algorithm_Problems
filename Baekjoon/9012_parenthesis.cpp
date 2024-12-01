#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		bool flag = false;
		stack<char> stk;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(')
			{
				stk.push('(');
			}
			else if (str[i] == ')') {
				if (stk.empty())
				{
					cout << "NO" << endl;
					flag = true;
					break;
				}

				stk.pop();
			}
		}

		if (!stk.empty()) cout << "NO" << endl;
		else if (!flag) cout << "YES" << endl;

	}
}