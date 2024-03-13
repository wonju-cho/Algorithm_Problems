#include<iostream>
#include<queue>

using namespace std;

int W = 8;
int H = 8;
char board[8][8];
bool v[9][8][8];
pair<int, int> movement[9] = { {1,0}, {-1,0}, {0,1}, {0,-1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {0,0}};

struct WJ
{
	pair<int, int> p;
	int time = 0;
};

bool BFS()
{
	queue<WJ> q;
	q.push({ { H - 1, 0 } });
	v[0][H-1][0] = true;

	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();

		if (curr.p.first == 0 && curr.p.second == W-1 || curr.time >= 8) return true;

		for(int i = 0; i < 9; i++)
		{
			int dy = curr.p.first + movement[i].first;
			int dx = curr.p.second + movement[i].second;

			if (dy < 0 || dy >= H || dx < 0 || dx >= W) continue;

			if (dy - curr.time >= 0 && board[dy - curr.time][dx] == '#') continue;

			if (dy - curr.time - 1 >= 0 && board[dy - curr.time - 1][dx] == '#') continue;

			if (!v[curr.time + 1][dy][dx])
			{
				v[curr.time + 1][dy][dx] = true;
				q.push({ { dy,dx }, curr.time + 1 });
			}

		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool isWallExist = false;
	for(int y = 0; y < H; y++)
	{
		for(int x = 0; x < W; x++)
		{
			char temp = 0;
			cin >> temp;
			if (temp == '#') {
				isWallExist = true;
			}
			board[y][x] = temp;
		}
	}

	if(!isWallExist)
	{
		cout << true;
		return 0;
	}

	cout << BFS();
}