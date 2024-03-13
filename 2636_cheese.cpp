#include<iostream>
#include<queue>

using namespace std;

int b[102][102];

int W;
int H;
int cheese = 0;
int cnt = 0;

pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int BFS()
{
	bool v[102][102] = {};
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	v[0][0] = true;
	cnt = 0;

	while (!q.empty())
	{
		auto p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = p.first + movement[i].first;
			int dx = p.second + movement[i].second;

			if (dy < 0 || dy >= H || dx < 0 || dx >= W) continue;

			if (v[dy][dx]) continue;

			if(b[dy][dx] == 0)
			{
				q.push({ dy,dx });
			}
			else if (b[dy][dx] == 1)
			{
				b[dy][dx] = 0;
				cnt++;
			}
			v[dy][dx] = true;
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H;
	cin >> W;

	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			int temp = 0;
			cin >> temp;
			b[y][x] = temp;
		}
	}

	int time = -1;
	do
	{
		cnt = BFS();
		if (cnt > 0)
			cheese = cnt;
		time++;
	} while (cnt > 0);

	cout << time << "\n" << cheese;
}