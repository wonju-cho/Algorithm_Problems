#include<iostream>
#include<queue>

using namespace std;

#define INF 100000

bool visited[200002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start = 0;
	int end = 0;
	cin >> start;
	cin >> end;

	//days, x
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	pq.push({ 0 , start });

	while (!pq.empty())
	{
		int day = pq.top().first;
		int x = pq.top().second;
		int nextDay = 0;
		int nextX = 0;
		pq.pop();

		if (visited[x])continue;

		visited[x] = true;

		if (x == end) 
		{
			cout << day;
			break;
		}

		nextDay = day;
		nextX = x * 2;
		if(nextX <= INF && nextX >= 0)
		{
			pq.push({ nextDay, nextX });
		}

		nextDay = day + 1;
		nextX = x + 1;
		if (nextX <= INF && nextX >= 0)
		{
			pq.push({ nextDay, nextX });
		}

		nextDay = day + 1;
		nextX = x - 1;
		if (nextX <= INF && nextX >= 0)
		{
			pq.push({ nextDay, nextX });
		}
	}

}