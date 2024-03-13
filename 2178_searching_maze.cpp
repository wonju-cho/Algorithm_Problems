#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int BFS(vector<vector<bool>>& board, pair<int,int> goal)
{
	vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
	//y, x
	queue<pair<pair<int, int>, int>> q;
	q.push({ { 0, 0 }, 1 });
	visited[0][0] = true;

	while(!q.empty())
	{
		auto curr = q.front();
		pair<int, int> point = curr.first;
		int cnt = curr.second;
		q.pop();

		if (point.first == goal.first && point.second == goal.second)
			return curr.second;

		for(int i = 0; i < 4; i++)
		{
			int dy = point.first + movement[i].first;
			int dx = point.second + movement[i].second;

			if (dx < 0 || dx > goal.second || dy < 0 || dy > goal.first) continue;

			if (visited[dy][dx]) continue;

			if (board[dy][dx])
			{
				visited[dy][dx] = true;
				q.push({ { dy, dx }, cnt + 1 });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int h = 0;
	int w = 0;

	cin >> h;
	cin >> w;

	vector<vector<bool>> board(h, vector<bool>(w));

	for(int y = 0; y < h; y++)
	{
		string temp = "";
		cin >> temp;

		for(int x = 0; x < w; x++)
		{
			if (temp[x] == '1')
				board[y][x] = true;
		}
	}

	cout << BFS(board, { h - 1, w - 1 });

}