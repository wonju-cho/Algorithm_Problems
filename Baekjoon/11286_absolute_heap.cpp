#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for(int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;

		if(temp == 0)
		{
			if(pq.empty())
			{
				cout << "0\n";
			}
			else
			{
				cout << pq.top().second<<'\n';
				pq.pop();
			}
		}
		else
		{
			pq.push({ abs(temp), temp });
		}
	}

}