#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int b[50][50];
bool v[50][50];
int N = 0; int L = 0; int R = 0;
pair<int, int> movement[4] = {{1,0}, {-1,0}, {0,-1}, {0,1}};

void BFS(pair<int, int> s)
{
	queue<pair<int, int>> q;
	q.push(s);
	v[s.first][s.second] = true;
	vector<pair<int, int>> vec;
	vec.push_back(s);
	int total = b[s.first][s.second];

	while(!q.empty())
	{
		auto curr = q.front();
		q.pop();

		for (int m = 0; m < 4; m++)
		{
			int dy = curr.first + movement[m].first;
			int dx = curr.second + movement[m].second;

			if (dy < 0 || dy >= N || dx < 0 || dx >= N) continue;

			if (v[dy][dx]) continue;

			if (abs(b[curr.first][curr.second] - b[dy][dx]) >= L && abs(b[curr.first][curr.second] - b[dy][dx]) <= R)
			{
				q.push({ dy,dx });
				v[dy][dx] = true;
				vec.push_back({ dy,dx });
				total += b[dy][dx];
			}
		}
	}

	int average = total / vec.size();
	for(auto ve:vec)
	{
		b[ve.first][ve.second] = average;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	 cin >> N >> L >> R;

	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < N; x++)
		{
			cin >> b[y][x];
		}
	}

	bool flag = true;
	int res = 0;
	while(flag)
	{
		flag = false;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				for(int m = 0; m < 4; m++)
				{
					int dy = y + movement[m].first;
					int dx = x + movement[m].second;

					if (dy < 0 || dy >= N || dx < 0 || dx >= N) continue;

					if (v[dy][dx]) continue;

					if (abs(b[y][x] - b[dy][dx]) >= L && abs(b[y][x] - b[dy][dx]) <= R)
					{
						BFS({ dy,dx });
						flag = true;
					}
				}
			}
		}

		if (flag) res++;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				v[y][x] = false;
			}
		}
	}

	cout << res;
}