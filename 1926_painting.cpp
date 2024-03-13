#include<iostream>
#include<queue>

using namespace std;

pair<int, int> movement[4] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

int Y;
int X;
int board[501][501];
bool v[501][501];

int BFS(pair<int,int> p)
{
	int res = 0;
	queue<pair<int, int>> q;
	q.push(p);
	v[p.first][p.second] = true;

	while(!q.empty())
	{
		auto p = q.front();
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int dy = p.first + movement[i].first;
			int dx = p.second + movement[i].second;

			if (dy < 0 || dy >= Y || dx < 0 || dx >= X) continue;
			if (v[dy][dx] || board[dy][dx] == 0) continue;

			q.push({ dy,dx });
			v[dy][dx] = true;
			res++;
		}
	}
	return res + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Y;
	cin >> X;

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			int temp = 0;
			cin >> temp;
			board[y][x] = temp;
		}
	}

	int num = 0;
	int area = 0;
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if(!v[y][x] && board[y][x] == 1)
			{
				area = max(BFS({y,x}), area);
				num++;
			}
		}
	}

	cout << num << "\n";
	cout << area;
}