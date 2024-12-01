#include <iostream>
#include <queue>

using namespace std;

int W;
int H;
int K;
int board[201][201];
bool v[201][201][31];

pair<int, int> horseMovement[8] = { {1,-2}, {1,2}, {2,-1}, {2,1}, {-1, -2}, {-1,2}, {-2,-1}, {-2,1} };
pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

struct Monkey
{
	int K;
	pair<int, int> p = {0,0};
	int cnt = 0;
};

int BFS()
{
	queue<Monkey> q;
	q.push({ K });
	v[0][0][K] = true;

	while(!q.empty())
	{
		auto m = q.front();
		q.pop();

		if (m.p.first == H - 1 && m.p.second == W - 1)
			return m.cnt;

		for (int i = 0; i < 4; i++)
		{
			int dy = m.p.first + movement[i].first;
			int dx = m.p.second + movement[i].second;

			if (dy < 0 || dy >= H || dx < 0 || dx >= W) continue;

			if (v[dy][dx][m.K]|| board[dy][dx] == 1) continue;

			q.push({ m.K, {dy,dx}, m.cnt + 1 });
			v[dy][dx][m.K] = true;
		}

		if(m.K > 0)
		{
			for (int i = 0; i < 8; i++)
			{
				int dy = m.p.first + horseMovement[i].first;
				int dx = m.p.second + horseMovement[i].second;

				if (dy < 0 || dy >= H || dx < 0 || dx >= W) continue;

				if (v[dy][dx][m.K-1] || board[dy][dx] == 1) continue;

				q.push({ m.K - 1, {dy,dx}, m.cnt + 1 });
				v[dy][dx][m.K-1] = true;
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;

	cin >> W;
	cin >> H;

	for(int y = 0; y < H; y++)
	{
		for(int x = 0; x < W; x++)
		{
			int temp = 0;
			cin >> temp;
			board[y][x] = temp;
		}
	}

	cout << BFS();
}