#include<iostream>
#include<stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string temp;
	while (getline(cin, temp))
	{
		bool wrong = false;
		stack<char> stk;

		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == '(' || temp[i] == '[')
			{
				stk.push(temp[i]);
			}
			else if (temp[i] == ')')
			{
				if (!stk.empty() && stk.top() == '(')
					stk.pop();
				else
				{
					wrong = true;
					break;
				}
			}
			else if (temp[i] == ']')
			{
				if (!stk.empty() && stk.top() == '[')
					stk.pop();
				else
				{
					wrong = true;
					break;
				}
			}
		}

		if(temp[0] != '.')
		{
			if (stk.size() > 0)
				wrong = true;

			if (wrong)
				cout << "no\n";
			else
				cout << "yes\n";
		}
	}
}