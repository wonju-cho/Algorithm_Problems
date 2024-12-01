#include<iostream>
#include<queue>

using namespace std;

int N = 0;
int M = 0;
int T = 0;

struct Hero
{
	pair<int, int> point;
	int time;
	bool gram = false;
};

pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int visited[105][105][2];
int board[105][105];
pair<int, int> gramP;

int BFS(pair<int, int> start)
{
	queue<Hero> q;
	visited[start.first][start.second][0] = 0;
	q.push({ {0,0},0,false });

	while (!q.empty())
	{
		auto curr = q.front();
		auto point = curr.point;
		q.pop();

		if (curr.time > T) continue;

		if (point.first == gramP.first && point.second == gramP.second)
			curr.gram = true;

		if (point.first == N - 1 && point.second == M - 1)
		{
			return curr.time;
		}

		for (int m = 0; m < 4; m++)
		{
			int dy = point.first + movement[m].first;
			int dx = point.second + movement[m].second;

			if (dx < 0 || dx >= M || dy < 0 || dy >= N) continue;

			if (curr.gram)
			{
				if(visited[dy][dx][1] == 0)
				{
					visited[dy][dx][1] = curr.time + 1;
					q.push({ { dy,dx }, curr.time + 1, curr.gram });
				}
			}
			else
			{
				if (board[dy][dx] != 1 && visited[dy][dx][0] == 0)
				{
					visited[dy][dx][0] = curr.time + 1;
					q.push({ { dy,dx }, curr.time + 1, curr.gram });
				}
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;
	cin >> T;

	for (int y = 0; y < N; y++)
	{
		for(int x = 0; x < M; x++)
		{
			int temp = 0;
			cin >> temp;

			if (temp == 2) gramP = { y,x };
			board[y][x] = temp;

		}
	}

	int res = BFS({ 0,0 });

	if (res > 0 && res <= T) cout << res;
	else cout << "Fail";
}