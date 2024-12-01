#include<iostream>
#include<queue>
#include<vector>
#include<set>

using namespace std;

int W;
int H;
int board[1002][1002];
int group[1000001];
bool v[1002][1002];
vector<pair<int, int>> zeros;
pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int BFS(pair<int,int> s, int idx)
{
	int res = 0;
	queue<pair<int, int>> q;
	q.push(s);
	v[s.first][s.second] = true;
	board[s.first][s.second] = idx;

	while(!q.empty())
	{
		auto p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = p.first + movement[i].first;
			int dx = p.second + movement[i].second;

			if (dy < 0 || dy >= H || dx < 0 || dx >= W) continue;

			if (board[dy][dx] == 0 || v[dy][dx]) continue;

			v[dy][dx] = true;
			q.push({ dy,dx });
			board[dy][dx] = idx;
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

	cin >> H;
	cin >> W;

	for(int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			int temp = 0;
			cin >> temp;
			if (temp == 0)
				zeros.push_back({ y,x });
			board[y][x] = temp;
		}
	}

	int idx = 1;
	for(int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			if (board[y][x] == 1 && !v[y][x])
			{
				group[idx] = BFS({ y,x }, idx);
				idx++;
			}
		}
	}

	int res = -1;

	for(int i = 0; i < zeros.size(); i++)
	{
		auto p = zeros[i];

		set<int> num;
		for(int m = 0; m < 4; m++)
		{
			int dy = p.first + movement[m].first;
			int dx = p.second + movement[m].second;

			if (dy < 0 || dy >= H || dx < 0 || dx >= W) continue;

			if (board[dy][dx] == 0) continue;

			num.insert(board[dy][dx]);
		}

		int cnt = 1;
		for(auto n: num)
		{
			cnt += group[n];
		}

		res = max(cnt, res);
	}

	cout << res;
}