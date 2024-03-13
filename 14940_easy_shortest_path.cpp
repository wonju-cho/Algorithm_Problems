#include<iostream>
#include<queue>

using namespace std;

pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int arr[1002][1002];
int dist[1002][1002];
int h;
int w;

void BFS(pair<int,int> p)
{
	queue <pair<int, int>> q;
	q.push(p);
	dist[p.first][p.second] = 0;

	while (!q.empty())
	{
		auto point = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int dy = point.first + movement[i].first;
			int dx = point.second + movement[i].second;

			if (dx < 0 || dx >= w || dy < 0 || dy >= h) continue;

			if (dist[dy][dx] != -1) continue;

			if (arr[dy][dx] == 0) continue;

			dist[dy][dx] = dist[point.first][point.second] + 1;
			q.push({ dy,dx });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&dist[0][0], &dist[1002][1002], -1);

	cin >> h;
	cin >> w;

	pair<int, int> goal;
	for(int y = 0; y < h; y++)
	{
		for(int x = 0; x < w; x++)
		{
			int num = 0;
			cin >> num;

			if (num == 2) goal = { y,x };

			arr[y][x] = num;
		}
	}

	BFS(goal);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (arr[y][x] == 0) cout << "0 ";
			else cout << dist[y][x]<< " ";
		}
		cout << "\n";
	}
}