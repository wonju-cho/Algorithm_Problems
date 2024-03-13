#include<iostream>
#include<queue>
#include<set>

using namespace std;

pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int board[52][52];
bool visited[52][52];
int N;
int L;
int R;
bool flag = false;

bool DiffCheck(pair<int,int> c1, pair<int,int> c2)
{
	if (abs(board[c1.first][c1.second] - board[c2.first][c2.second]) >= L &&
		abs(board[c1.first][c1.second] - board[c2.first][c2.second]) <= R)
		return true;

	return false;
}

void BFS(pair<int,int> start)
{
	queue<pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = true;
	set<pair<int, int>> sUnity;

	while (!q.empty())
	{
		auto point = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dy = point.first + movement[i].first;
			int dx = point.second + movement[i].second;

			if (dy >= N || dy < 0 || dx >= N || dx < 0) continue;

			if (visited[dy][dx])
				continue;

			if(DiffCheck(point, {dy,dx}))
			{
				q.push({ dy,dx });
				sUnity.insert({ point.first, point.second });
				sUnity.insert({ dy, dx });
				visited[dy][dx] = true;
			}
		}
	}

	if(!sUnity.empty())
	{
		flag = true;
		int sum = 0;
		for (auto s : sUnity)
		{
			sum += board[s.first][s.second];
		}

		int population = sum / sUnity.size();
		for (auto s : sUnity)
		{
			board[s.first][s.second] = population;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> L;
	cin >> R;

	for (int y = 0; y < N; y++)
	{
		for(int x = 0; x < N; x++)
		{
			int temp = 0;
			cin >> temp;
			board[y][x] = temp;
		}
	}

	int res = 0;

	while(true)
	{
		flag = false;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if(!visited[y][x])
				{
					BFS({ y, x });
				}
			}
		}

		if (!flag) break;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				visited[y][x] = false;
			}
		}

		res++;
	}

	cout << res;
}