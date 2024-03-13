#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

struct STACK
{
	void push(int num)
	{
		stk.push(num);
	}

	int pop()
	{
		if (size() < 1) return -1;

		int num = top();
		stk.pop();

		return num;
	}

	int size()
	{
		return stk.size();
	}

	int empty()
	{
		if (size() == 0) return 1;
		else return 0;
	}

	int top()
	{
		if (size() < 1) return -1;
		return stk.top();
	}

private:
	stack<int> stk;
};

int main()
{
	ios_base::sync_with_stdio(false);

	STACK stk;

	int n = 0;
	cin >> n;

	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if(str == "push")
		{
			int temp = 0;
			cin >> temp;
			stk.push(temp);
		}
		if (str == "pop")
		{
			cout << stk.pop() << endl;
		}
		else if(str == "size")
		{
			cout << stk.size() << endl;
		}
		else if(str == "empty")
		{
			cout << stk.empty() << endl;
		}
		else if(str == "top")
		{
			cout << stk.top() <<endl;
		}
	}
}