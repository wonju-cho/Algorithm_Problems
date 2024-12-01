#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	//id, height
	stack<pair<int, int>> stk;

	stk.push({ 0, 100000001 });

	for(int i = 0; i < n; i++)
	{       
		int curr = 0;
		cin >> curr;

		if(curr < stk.top().second)
		{
			cout<<stk.top().first<<" ";
		}
		else
		{
			while (stk.top().second < curr)
			{
				stk.pop();
			}
			cout<<stk.top().first<<" ";;
		}

		stk.push({ i + 1, curr });    
	}

}

//ver 2
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num = 0;
	cin >> num;

	stack<pair<int,int>> stk;
	stk.push({-1,0});

	for (int i = 0; i < num; i++)
	{
		int temp = 0;
		cin >> temp;

		if (stk.top().first < temp)
		{
			while (stk.top().first < temp)
			{
				if (stk.top().first == -1)
					break;
				stk.pop();
			}
			cout << stk.top().second << " ";
		}
		else
		{
			cout << stk.top().second << " ";
		}
		stk.push({ temp, i + 1 });
	}

}