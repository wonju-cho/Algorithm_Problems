#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
	cin >> str;

	stack<char> stk;
	int ans = 0;
	int temp = 1;
    
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == '(')
		{
			stk.push('(');
			temp *= 2;
		}
		else if (str[i] == '[')
		{
			stk.push('[');
			temp *= 3;
		}
		else if(str[i] == ')')
		{
			if (stk.empty() || stk.top() != '(') {
				cout<<"0";
				return 0; 
			}

			if(str[i-1] == '(')
			{
				ans += temp;
				temp /= 2;
				stk.pop();
			}
			else
			{
				temp /= 2;
				stk.pop();
			}
		}
		else
		{
			if (stk.empty() || stk.top() != '[') {
				cout<<"0";
				return 0;
			}

			if (str[i - 1] == '[')
			{
				ans += temp;
				temp /= 3;
				stk.pop();
			}
			else
			{
				temp /= 3;
				stk.pop();
			}
		}
	}
	
	if(!stk.empty())
	{
		cout<<"0";
	}
	else
	{
		cout<<ans;
	}

}