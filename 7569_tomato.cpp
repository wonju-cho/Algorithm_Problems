#include<iostream>
#include<queue>

using namespace std;

struct Point
{
	int z;
	int y;
	int x;
};

Point movement[6] = { {1,0,0}, {-1,0,0} , {0,1, 0}, {0,-1, 0}, {0,0,1}, {0,0,-1} };

int board[106][106][106];
int M;
int N;
int H;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&board[0][0][0], &board[105][105][105], -1);

	cin >> M;
	cin >> N;
	cin >> H;

	queue<pair<Point, int>> q;
	int size = 0;
	for(int z = 0; z < H; z++)
	{
		for(int y = 0; y < N; y++)
		{
			for(int x = 0; x < M; x++)
			{
				int num = 0;
				cin >> num;

				if (num == 0)
				{
					size++;
					board[z][y][x] = num;
				}
				else if(num == 1)
				{
					q.push({ {z,y,x}, 0 });
					board[z][y][x] = num;
				}

			}
		}
	}

	if (size == 0)
	{
		cout << 0;
		return 0;
	}

	int res = 0;
	while(!q.empty())
	{
		auto point = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int m = 0; m < 6; m++)
		{
			int dz = point.z + movement[m].z;
			int dy = point.y + movement[m].y;
			int dx = point.x + movement[m].x;

			if (dx < 0 || dx >= M || dy < 0 || dy >= N || dz < 0 || dz >= H) continue;

			if (board[dz][dy][dx] != 0) continue;

			q.push({ { dz,dy,dx }, cnt + 1 });
			size--;
			board[dz][dy][dx] = 1;
			
		}
		res = cnt;
	}

	if (size != 0) cout << -1;
	else cout << res;
}