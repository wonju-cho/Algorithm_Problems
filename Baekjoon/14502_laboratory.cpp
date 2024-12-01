#include<iostream>
#include<queue>

using namespace std;

int b[10][10];
int b2[10][10];

pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int N;
int M;

int BFS()
{
	bool v[10][10] = {};
	int res = 0;

	for(int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			b2[y][x] = b[y][x];
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if(b2[y][x] == 2)
			{
				queue<pair<int, int>> q;
				q.push({ y,x });
				v[y][x] = true;

				while(!q.empty())
				{
					auto point = q.front();
					q.pop();

					for(int i = 0; i < 4; i++)
					{
						int dy = point.first + movement[i].first;
						int dx = point.second + movement[i].second;

						if (dx < 0 || dx >= M || dy < 0 || dy >= N) continue;

						if (v[dy][dx]) continue;

						if (b2[dy][dx] == 0)
						{
							v[dy][dx] = true;
							q.push({ dy, dx });
							b2[dy][dx] = 2;
						}
					}
				}
			}
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (b2[y][x] == 0)
				res++;
		}
	}

	return res;
}

void combine(vector<pair<int, int>>& empty, int start, int count, int& maxSafeArea) {
	if (count == 3) {
		maxSafeArea = max(maxSafeArea, BFS());
		return;
	}

	for (int i = start; i < empty.size(); ++i) {
		b[empty[i].first][empty[i].second] = 1;
		combine(empty, i + 1, count + 1, maxSafeArea);
		b[empty[i].first][empty[i].second] = 0; 
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;

	vector<pair<int, int>> empty;

	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < M; x++)
		{
			int temp = 0;
			cin >> temp;

			if (temp == 0)
				empty.push_back({ y,x });

			b[y][x] = temp;
		}
	}

	int res = 0;
	combine(empty, 0, 0, res);
	cout << res;
}