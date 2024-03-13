#include <iostream>
#include <queue>

using namespace std;

int W;
int H;
int board[1001][1001];
bool v[2][1001][1001];
pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

struct P
{
	pair<int, int> p = {0,0};
	int cnt = 1;
	bool canBreak = true;
};

int BFS()
{
	queue<P> q;
	q.push({});
	v[1][0][0] = true;
	v[0][0][0] = true;

	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();

		if (curr.p.first == H - 1 && curr.p.second == W - 1) return curr.cnt;

		for(int i = 0; i < 4; i++)
		{
			int dy = curr.p.first + movement[i].first;
			int dx = curr.p.second + movement[i].second;

			if (dy < 0 || dy >= H || dx < 0 || dx >= W) continue;

			if (v[curr.canBreak][dy][dx]) continue;

			if(curr.canBreak)
			{
				if(board[dy][dx] == 1)
				{
					v[!curr.canBreak][dy][dx] = true;
					q.push({ { dy,dx },  curr.cnt + 1 ,  !curr.canBreak });
				}
				else
				{
					v[curr.canBreak][dy][dx] = true;
					q.push({ { dy,dx },  curr.cnt + 1 ,  curr.canBreak });
				}
			}
			else
			{
				if (board[dy][dx] == 1) continue;

				v[curr.canBreak][dy][dx] = true;
				q.push({ {dy,dx}, curr.cnt + 1, curr.canBreak });
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

	cin >> H;
	cin >> W;

	for(int y = 0; y < H; y++)
	{
		string temp = "";
		cin >> temp;

		for (int x = 0; x < W; x++)
		{
			board[y][x] = temp[x] - '0';
		}
	}

	cout << BFS();
}