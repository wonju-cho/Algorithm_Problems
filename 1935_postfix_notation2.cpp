#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

int main() {
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	string notation;
	cin >> notation;

	unordered_map<char, double> um;
	char c = 'A';
	for(int i = 0; i < n; i++, c++)
	{
		double num = 0;
		cin >> num;
		um[c] = num;
	}

	double res = 0.f;
	string str;
	stack<double> stk;

	for(int i = 0; i < notation.length(); i++)
	{
		if(isalpha(notation[i]))
		{
			stk.push(um[notation[i]]);
		}
		else
		{
			double temp1 = stk.top();
			stk.pop();
			double temp2 = stk.top();
			stk.pop();
			double num = 0.f;

			if (notation[i] == '+')
			{
				num += temp1 + temp2;
			}
			else if (notation[i] == '-')
			{
				num += temp2 - temp1;
			}
			else if (notation[i] == '*')
			{
				num += temp1 * temp2;
			}
			else
			{
				num += temp2 / temp1;
			}

			stk.push(num);
		}
	}

	res = stk.top();
	printf("%.2f", res);

}