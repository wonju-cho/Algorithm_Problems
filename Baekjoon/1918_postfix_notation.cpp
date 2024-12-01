#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<char> stk;
    string result = "";
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i])) {

			if (str[i] == '(')
			{
				stk.push(str[i]);
			}
			else if (str[i] == ')')
			{
				while (!stk.empty() && stk.top() != '(')
				{
					char temp = stk.top();
					result += temp;
					stk.pop();
				}
				stk.pop();
			}
			else if (str[i] == '*' || str[i] == '/')
			{
				while (!stk.empty() && (stk.top() == '*' || stk.top() == '/'))
				{
					char temp = stk.top();
					result += temp;
					stk.pop();
				}
				stk.push(str[i]);
			}
			else if (str[i] == '+' || str[i] == '-')
			{
				while (!stk.empty() && stk.top() != '(')
				{
					char temp = stk.top();
					result += temp;
					stk.pop();
				}
				stk.push(str[i]);
			}
		}
		else
		{
			result += str[i];
		}
	}

	while (!stk.empty())
	{
		char temp = stk.top();
		stk.pop();
		result += temp;
	}
	cout << result << "\n";


}