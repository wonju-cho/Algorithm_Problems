#include<iostream>
#include<vector>

using namespace std;

char board[10][10];
char res[10][10];

pair<int, int> movement[8] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; cin >> N;
	vector<pair<int, int>> vec;
	for(int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			char temp; cin >> temp;
			if (temp == '*')
				vec.push_back({ y,x });
			board[y][x] = temp;
		}
	}

	bool flag = false;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			char temp; cin >> temp;
			int cnt = 0;

			if (temp == 'x')
			{
				if (board[y][x] == '*' && !flag)
				{
					flag = true;
					continue;
				}

				for (int m = 0; m < 8; m++)
				{
					int dy = y + movement[m].first;
					int dx = x + movement[m].second;

					if (dy < 0 || dy >= N || dx < 0 || dx >= N) continue;

					if (board[dy][dx] == '*')
						cnt++;
				}
				res[y][x] = cnt + '0';
			}
			else
				res[y][x] = temp;
		}
	}

	if(flag)
	{
		for (auto v : vec)
		{
			res[v.first][v.second] = '*';
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << res[y][x];
		}
		cout << "\n";
	}
}