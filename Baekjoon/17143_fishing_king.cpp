#include <iostream>
#include <vector>

using namespace std;
#define MAX 101
int R; int C; int M;
int rRound; int cRound;

pair<int, int> dirs[5] = { {-1,-1}, {-1,0}, {1,0}, {0,1}, {0,-1} };

struct Shark {
	pair<int, int> p;
	int v;
	int dir;
	int size;
};

//shark id
int b[MAX][MAX];

//get info with id
Shark track[MAX * MAX];

bool BoundaryCheck(pair<int, int> p) {

	if (p.first < 0 || p.first >= R || p.second < 0 || p.second >= C) return false;

	return true;
}

void Clear(int id) {
	track[id].p = { -1,-1 };
	track[id].v = -1;
	track[id].dir = -1;
	track[id].size = -1;
}

void MoveShark() {

	vector<int> temp[MAX][MAX];

	for (int i = 1; i <= M; i++)
	{
		//if (track[i].size == -1 || track[i].v == 0) continue;
		if (track[i].size == -1) continue;

		pair<int, int> targetP = track[i].p;
		int dir = track[i].dir;
		b[targetP.first][targetP.second] = 0;

		for (int v = 0; v < track[i].v; v++)
		{
			targetP.first += dirs[dir].first; targetP.second += dirs[dir].second;
			if (!BoundaryCheck(targetP)) {
				targetP.first -= dirs[dir].first; targetP.second -= dirs[dir].second;
				if (dir == 1) dir++;
				else if (dir == 2) dir--;
				else if (dir == 3) dir++;
				else dir--;
				targetP.first += dirs[dir].first; targetP.second += dirs[dir].second;
			}
		}

		temp[targetP.first][targetP.second].push_back(i);
		track[i].p = { targetP.first, targetP.second };
		track[i].dir = dir;
	}

	for (int i = 1; i <= M; i++)
	{
		if (track[i].size == -1 || temp[track[i].p.first][track[i].p.second].size() == 1) continue;

		auto p = track[i].p;
		int max = -1;
		for (int t = 0; t < temp[p.first][p.second].size(); t++)
		{
			if (track[temp[p.first][p.second][t]].size > max)
				max = track[temp[p.first][p.second][t]].size;
		}

		for (int t = 0; t < temp[p.first][p.second].size(); t++)
		{
			if (track[temp[p.first][p.second][t]].size < max)
			{
				Clear(temp[p.first][p.second][t]);
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		if (track[i].size == -1) continue;

		auto p = track[i].p;
		b[p.first][p.second] = i;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int res = 0;
	cin >> R >> C >> M;
	rRound = (R - 1) * 2; cRound = (C - 1) * 2;
	for (int i = 1; i <= M; i++)
	{
		int r, c, s, d, z; cin >> r >> c >> s >> d >> z;

		if (d == 1 || d == 2)
			s %= rRound;
		else s %= cRound;

		track[i] = { {r - 1,c - 1}, s, d, z };
		b[r - 1][c - 1] = i;
	}

	for (int i = 0; i < C; i++)
	{
		for (int y = 0; y < R; y++)
		{
			if (b[y][i] != 0)
			{
				res += track[b[y][i]].size;
				Clear(b[y][i]);
				b[y][i] = 0;
				break;
			}
		}

		MoveShark();
	}

	cout << res;
}