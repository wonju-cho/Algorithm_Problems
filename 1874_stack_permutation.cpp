#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n = 0;
	cin >> n;

	stack<int> stk;
	int cnt = 1;
	string test = "";

	stk.push(0);

	while (!stk.empty())
	{
		int num = 0;
		cin >> num;

		if (stk.top() > num)
		{
			test.clear();
			cout << "NO";
			return 0;
		}

		while(cnt <= num)
		{
			stk.push(cnt);
			test += '+';
			cnt+=1;
		}
		
		if(stk.top() == num)
		{
			stk.pop();
			test += '-';
		}

	}

	for (int i = 0; i < test.length() - 1; i++)
	{
		cout << test[i] << "\n";
	}


}