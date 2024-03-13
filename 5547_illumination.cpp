#include<iostream>
#include<queue>

using namespace std;

int b[102][102];
bool v[102][102];

vector<vector<pair<int, int>>> movement = {
	{{-1,-1}, {0,-1}, {-1,0}, {1,0}, {0,1}, {1,-1} } , //even
	{{-1, 1}, {0, -1}, {-1, 0}, {1, 0}, {0, 1}, {1, 1}} }; //odd

int W;
int H;

void BFS(pair<int,int> start)
{
	queue<pair<int, int>> q;
	q.push(start);
	v[start.first][start.second] = true;
	b[start.first][start.second] = 2;

	while(!q.empty())
	{
		auto curr = q.front();
		q.pop();

		for(int i = 0; i < 6; i++)
		{
			int dy = (curr.first % 2) ? curr.first + movement[0][i].first : curr.first + movement[1][i].first;
			int dx = (curr.first % 2) ? curr.second + movement[0][i].second : curr.second + movement[1][i].second;

			if (dy < 0 || dy >= H || dx < 0 || dx >= W) continue;

			if (v[dy][dx]) continue;

			if(b[dy][dx] == 0)
			{
				q.push({ dy,dx });
				v[dy][dx] = true;
				b[dy][dx] = 2;
			}
		}
	}

}

int Count(pair<int,int> p)
{
	int res = 0;
	for(int i = 0; i < 6; i++)
	{
		if(p.first % 2 == 0)
		{
			int dy = p.first + movement[1][i].first;
			int dx = p.second + movement[1][i].second;

			if (dy < 0 || dy >= H || dx < 0 || dx >= W || b[dy][dx] == 2) res++;
		}
		else
		{
			int dy = p.first + movement[0][i].first;
			int dx = p.second + movement[0][i].second;

			if (dy < 0 || dy >= H || dx < 0 || dx >= W || b[dy][dx] == 2) res++;
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> W;
	cin >> H;

	for(int y = 0; y < H; y++)
	{
		for(int x = 0; x < W; x++)
		{
			int temp = 0;
			cin >> temp;
			b[y][x] = temp;
		}
	}

	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			if (b[y][x] == 0 && (x == 0 || x == W - 1 || y == 0 || y == H - 1) && !v[y][x])
			{
				BFS({y,x});
			}
		}
	}

	int ans = 0;
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			if(b[y][x] == 1)
			{
				ans += Count({ y,x });
			}
		}
	}
	cout << ans;
}