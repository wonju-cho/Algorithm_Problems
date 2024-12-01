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
	string test = "";
	for(int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' && str[i + 1] == ')')
		{
			ans += stk.size();
			i++;
		}
		else if(str[i] == '(')
		{
			stk.push('(');
		}
		else if(str[i] == ')')
		{
			ans += 1;
			stk.pop();
		}

	}

	cout<<ans;

}