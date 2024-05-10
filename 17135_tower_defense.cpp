#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
#define MAX 16
int N; int M; int D;
bool b[MAX][MAX]; //원래 맵
bool archerV[MAX]; //조합 리스트
int res;
vector<int> archer(3);
pair<int, int> movement[3] = { {-1, 0}, {0,-1}, {0, 1}};

pair<int,int> BFS(pair<int,int> pos, bool (&arr)[MAX][MAX])
{
	int minDist = 99;
	bool v[MAX][MAX] = {};
	pair<int,int> goal {-1,-1};
	queue<pair<pair<int, int>, int>> q;
	q.push({ pos, 0 });
	
	while (!q.empty())
	{
		pair<int, int> p = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (dist >= D || minDist < dist)
		{
			continue;
		}

		for (int m = 0; m < 3; m++)
		{
			int dy = movement[m].first + p.first;
			int dx = movement[m].second + p.second;

			if (dy < 0 || dy >= N || dx < 0 || dx >= M) continue;

			if (v[dy][dx]) continue;

			if (arr[dy][dx] == true)
			{
				if (minDist > dist + 1) {
					minDist = dist + 1;
					goal = { dy,dx };
				}

				if(minDist == dist + 1)
				{
					if(dx < goal.second)
					{
						goal = { dy,dx };
					}
				}
			}

			v[dy][dx] = true;
			q.push({ { dy, dx }, dist + 1 });
		}
	}

	return goal;
}

int Simulation()
{
	bool temp[MAX][MAX] = {}; //보드 값 가져온거
	set<pair<int, int>> pos;
	int cnt = 0;

	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < M; x++)
		{
			temp[y][x] = b[y][x];
		}
	}

	for(int y = N; y > 0; y--)
	{
		for(int i = 0; i < 3; i++)
		{
			if(D == 1)
			{
				if(b[y - 1][archer[i]] == true)
				{
					cnt++;
				}
			}
			else
			{
				auto p = BFS({ y, archer[i] }, temp);
				if (p != pair<int,int>{-1, -1}) {
					pos.insert(p);
				}
			}
		}

		for(auto p : pos)
		{
			temp[p.first][p.second] = false;
		}

		for(int x = 0; x < M; x++)
		{
			temp[y - 1][x] = false;
		}
	}

	if (D > 1) cnt = pos.size();

	return cnt;
}

void MakeCombination(int curr, int prev)
{
	if(curr == 3)
	{
		res = max(Simulation(), res);
		return;
	}

	for(int i = 0; i < M; i++)
	{
		if(!archerV[i] && i > prev)
		{
			archerV[i] = true;
			archer[curr] = i;
			MakeCombination(curr + 1, i);
			archerV[i] = false;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> D;
	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < M; x++)
		{
			cin >> b[y][x];
		}
	}

	MakeCombination(0, -1);

	cout << res;
}