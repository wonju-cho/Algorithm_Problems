#include<iostream>
#include<deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> T;

	while(T > 0)
	{
		bool reverse = false;
		bool error = false;
		string command = "";
		cin >> command;

		int N = 0;
		cin >> N;
		deque<int> dq;

		string temp = "";
		cin >> temp;

		int j = 0;
		while(dq.size() != N)
		{
			if (temp[j] != '[' && temp[j] != ']' && temp[j] != ',')
			{
				string str = "";
				while (temp[j] != ',' && temp[j] != ']')
				{
					str += temp[j];
					j++;
				}
				dq.push_back(stoi(str));
			}
			j++;
		}
		

		for(int i = 0; i < command.length(); i++)
		{
			if(command[i] == 'R')
			{
				reverse = !reverse;
			}
			else
			{
				if (dq.empty())
				{
					error = true;
					cout << "error\n";
					break;
				}

				if(reverse)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
		}

		if(!error)
		{
			cout << "[";
			if (reverse)
			{
				for (auto iter = dq.rbegin(); iter != dq.rend(); iter++)
				{
					if(iter+1 != dq.rend())
						cout << *iter << ",";
					else
						cout << *iter;
				}
			}
			else
			{
				for(auto iter = dq.begin(); iter != dq.end(); iter++)
				{
					if(iter+1 != dq.end())
						cout << *iter << ",";
					else
						cout << *iter;
				}
			}
			cout << "]\n";
		}
		
		T--;
	}

}
