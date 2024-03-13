#include<iostream>
#include<queue>
#include<vector>

using namespace std;

pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int h;
int w;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h;
	cin >> w;
	int sec = 0;
	cin >> sec;

	vector<vector<char>> board(h, vector<char>(w, '.'));

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			char c;
			cin >> c;

			if (c == 'O')
			{
				board[y][x] = c;
			}
		}
	}

	if(sec % 2 == 0)
	{
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				cout << "O";
			}
			cout << '\n';
		}
	}
	else
	{
		int cnt = 1;
		while(cnt < sec)
		{
			queue<pair<int, int>> q;

			for (int y = 0; y < h; y++)
			{
				for (int x = 0; x < w; x++)
				{
					if (board[y][x] == 'O')
					{
						q.push({ y,x });
					}
				}
			}

			for (int y = 0; y < h; y++)
			{
				for (int x = 0; x < w; x++)
				{
					board[y][x] = 'O';
				}
			}

			while (!q.empty())
			{
				auto point = q.front();
				q.pop();

				board[point.first][point.second] = '.';

				for (int m = 0; m < 4; m++)
				{
					int dy = point.first + movement[m].first;
					int dx = point.second + movement[m].second;

					if (dx < 0 || dx >= w || dy < 0 || dy >= h) continue;

					board[dy][dx] = '.';
				}
			}

			cnt += 2;
		}

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				cout << board[y][x];
			}
			cout << '\n';
		}
	}
}