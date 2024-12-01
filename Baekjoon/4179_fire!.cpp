#include<iostream>
#include<queue>

using namespace std;
#define MAXW 1001
#define MAXH 1001

int H;
int W;
int cnt;
char b[MAXH][MAXW];
bool v[MAXH][MAXW];
int	fireB[MAXH][MAXW]; //store the time of the fire spread out
queue<pair<int, int>> fireQ;

pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void FireMapUpdate()
{
	while (!fireQ.empty())
	{
		int size = fireQ.size();

		for(int f = 0; f < size; f++)
		{
			auto p = fireQ.front();
			fireQ.pop();

			for (int i = 0; i < 4; i++)
			{
				int dy = p.first + movement[i].first;
				int dx = p.second + movement[i].second;

				if (dy < 0 || dy >= H || dx < 0 || dx >= W) continue;

				if (b[dy][dx] != '#')
				{
					if (fireB[dy][dx] > fireB[p.first][p.second] + 1)
					{
						fireB[dy][dx] = fireB[p.first][p.second] + 1;
						fireQ.push({ dy,dx });
					}
				}
			}
		}
	}
}

struct Jihoon
{
	pair<int, int> p;
	int walk = 0;
};

int Simulation(pair<int,int> s)
{
	queue<Jihoon> q;
	q.push({ s });
	v[s.first][s.second] = true;

	while(!q.empty())
	{
		auto j = q.front();
		q.pop();

		if (j.p.first == 0 || j.p.first == H - 1 || j.p.second == 0 || j.p.second == W - 1)
			return j.walk+1;

		for (int i = 0; i < 4; i++)
		{
			int dy = j.p.first + movement[i].first;
			int dx = j.p.second + movement[i].second;

			if (dy < 0 || dy >= H || dx < 0 || dx >= W) continue;

			if (v[dy][dx] || b[dy][dx] == '#') continue;

			if(j.walk + 1 < fireB[dy][dx])
			{
				q.push({ {dy,dx}, j.walk + 1 });
				v[dy][dx] = true;
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

	cin >> H; cin >> W;

	pair<int, int> start;

	for(int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			char temp;
			cin >> temp;

			if (temp == 'F')
			{
				fireB[y][x] = 0;
				fireQ.push({ y,x });
			}
			else if (temp == 'J')
				start = { y,x };
			else
			{
				fireB[y][x] = ~0U >> 2;
			}
			b[y][x] = temp;
		}
	}

	FireMapUpdate();

	int res = Simulation(start);
	if (res == -1)
		cout << "IMPOSSIBLE";
	else
		cout << res;
}