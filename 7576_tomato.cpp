#include<iostream>
#include<queue>

using namespace std;

pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int board[1005][1005];
int h;
int w;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&board[0][0], &board[1002][1002], -1);

	cin >> w;
	cin >> h;

	queue<pair<pair<int, int>, int>> q;
	int size = 0;
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int n;
			cin >> n;

			if (n == 1) {
				q.push({ {y,x}, 0 });
				board[y][x] = n;
			}
			else if (n == 0) {
				size++;
				board[y][x] = n;
			}

		}
	}

	int res = 0;
	while(!q.empty())
	{
		auto point = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int m = 0; m < 4; m++)
		{
			int dy = point.first + movement[m].first;
			int dx = point.second + movement[m].second;

			if (dx < 0 || dx >= w || dy < 0 || dy >= h) continue;

			if (board[dy][dx] != 0) continue;

			q.push({ { dy,dx }, cnt + 1 });
			size--;
			board[dy][dx] = 1;
			
		}
		res = cnt;
	}

	if (size != 0) cout << -1;
	else cout << res;
}