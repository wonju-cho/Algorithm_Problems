#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int testCases = 0;
	cin >> testCases;

	for(int i = 0; i < testCases; i++)
	{
		queue<pair<int, int>> q;

		int n = 0;
		cin >> n;

		int target = 0;
		cin >> target;

		//can replace to a priority queue
		vector<int> priorities;

		for(int i = 0; i < n; i++)
		{
			int priority = 0;
			cin >> priority;
			q.push({ i, priority });
			priorities.push_back(priority);
		}
		sort(priorities.begin(), priorities.end());

		int cnt = 1;
		int maximum = priorities.back();
		while(true)
		{
			while (q.front().second != maximum)
			{
				q.push({ q.front().first, q.front().second });
				q.pop();
			}

			if (q.front().first == target) break;

			q.pop();
			cnt++;
			maximum = priorities[priorities.size() - cnt];
		}

		cout<<cnt<<"\n";
		
	}
    
}