#include <iostream>
#include <queue>

using namespace std;
bool arr[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
        priority_queue<pair<int, int>> pq1;
	    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
		
        int t = 0;
		cin >> t;

		for(int j = 0; j < t; j++)
		{
			string command;
			int num;
			cin >> command;
			cin >> num;

			if(command == "I")
			{
				pq1.push({num, j});
				pq2.push({num, j});
				arr[j] = true;
			}
			else if(command == "D")
			{
				if(num == 1)
				{
					while(!pq1.empty())
					{
						auto idx = pq1.top().second;
						if (arr[idx] == 1) break;
						pq1.pop();
					}

					if(!pq1.empty())
					{
						arr[pq1.top().second] = false;
					}
				}
				else
				{
					while (!pq2.empty())
					{
						auto idx = pq2.top().second;
						if (arr[idx] == 1) break;
						pq2.pop();
					}

					if (!pq2.empty())
					{
						arr[pq2.top().second] = false;
					}
				}
			}
		}

		while (!pq1.empty())
		{
			auto idx = pq1.top().second;
			if (arr[idx] == 1) break;
			pq1.pop();
		}
        
		while (!pq2.empty())
		{
			auto idx = pq2.top().second;
			if (arr[idx] == 1) break;
			pq2.pop();
		}

		if (pq1.empty() || pq2.empty())
		{
			cout<<"EMPTY\n";
		}
		else
		{
			cout<<pq1.top()<<" "<<pq2.top()<<"\n";
		}
	}
}