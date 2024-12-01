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
	
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for(int i = 0; i < n * n; i++)
	{
		int temp = 0;
		cin >> temp;
	
		if (i < n)
			pq.push(temp);
		else
		{
			if (pq.top() < temp)
			{
				pq.pop();
				pq.push(temp);
			}
		}
	}
	
	cout << pq.top();
}