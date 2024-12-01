#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int H;
int W;
int cnt;
pair<int, int> point;
int b[303][303];

pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void Update()
{
	cnt = 0;
	bool flag = false;
	int copy[303][303] = {};

	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			copy[y][x] = b[y][x];
		}
	}

	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			if (b[y][x] == 0) continue;

			int adjacent = 0;
			for(int i = 0; i < 4; i++)
			{
				int dy = y + movement[i].first;
				int dx = x + movement[i].second;

				if (dy < 0 || dy >= H || dx < 0 || dx >= W) continue;

				if (copy[dy][dx] == 0)
					adjacent++;
			}

			if (copy[y][x] - adjacent < 0)
				b[y][x] = 0;
			else
			{
				b[y][x] -= adjacent;
				if (!flag && b[y][x] != 0)
				{
					point = { y,x };
					flag = true;
				}
			}
			if (b[y][x] != 0) cnt++;
		}
	}
}

bool BFS()
{
	int temp = cnt - 1;
	queue<pair<int, int>> q;
	q.push(point);
	vector<vector<bool>> v(H, vector<bool>(W, false));
	v[point.first][point.second] = true;

	while(!q.empty())
	{
		auto p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = p.first + movement[i].first;
			int dx = p.second + movement[i].second;

			if (dy < 0 || dy >= H || dx < 0 || dx >= W) continue;

			if (v[dy][dx]) continue;

			if(b[dy][dx]!= 0)
			{
				q.push({ dy,dx });
				v[dy][dx] = true;
				temp--;
			}
		}
	}

	if (temp == 0) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H; cin >> W;

	for(int y = 0; y < H; y++)
	{
		for(int x = 0; x < W; x++)
		{
			int temp = 0;
			cin >> temp;

			if (temp != 0)
			{
				point = { y,x };
				cnt++;
			}

			b[y][x] = temp;
		}
	}

	int res = 0;
	while(cnt > 0)
	{
		Update();
		res++;
		if (!BFS())
		{
			if (cnt == 0) cout << 0;
			else
			{
				cout << res;
				return 0;
			}
			
		}
	}
}