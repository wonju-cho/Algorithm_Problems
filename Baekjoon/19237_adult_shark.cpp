#include <iostream>
#include <vector>

using namespace std;

struct Shark
{
	pair<int, int> p;
	int dir;
	int k;
	vector<vector<int>> dirsInfo;
	bool isExist = true;
};

struct Info
{
	int k = -1;
	int id = 401;
};

#define MAX 20
pair<int, int> dirs[5] = { {-1,-1}, { -1,0 }, {1,0}, {0,-1}, {0,1} };
int N; int M; int k;
int cnt;

Info b[MAX][MAX];
Info temp[MAX][MAX];
Shark track[MAX * MAX];

bool BoundaryCheck(pair<int, int> p)
{
	if (p.first < 0 || p.first >= N || p.second < 0 || p.second >= N) return false;
	return true;
}

void RemoveSmell()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (b[y][x].id == 0) continue;

			//if a shark exists, then ignore 
			if (track[b[y][x].id].isExist && track[b[y][x].id].p == pair<int, int>{y, x}) continue;

			//subtract 1 from k value only if the value is greater than 0
			if (b[y][x].k > 0)
			{
				b[y][x].k -= 1;

				if (b[y][x].k == 0)
					b[y][x].id = 0;
			}
		}
	}
}

int GetPreferDir(pair<int, int> p, vector<int> dir, bool flag)
{
	//bool false: empty | true: smell
	for (int m = 0; m < 4; m++)
	{
		auto targetP = p;
		targetP.first += dirs[dir[m]].first; targetP.second += dirs[dir[m]].second;

		if (!BoundaryCheck(targetP)) continue;

		if (!flag)
		{
			if (b[targetP.first][targetP.second].id == 0)
			{
				return dir[m];
			}
		}
		else
		{
			if (b[targetP.first][targetP.second].id == b[p.first][p.second].id)
			{
				return dir[m];
			}
		}
	}
	return -1;
}

bool CanMove(pair<int, int> p, int id)
{
	if (temp[p.first][p.second].id == 0)
	{
		return true;
	}

	if (temp[p.first][p.second].id < id)
	{
		return false;
	}

	return true;
}

void Update(int id, pair<int, int> targetPoint, int targetDir)
{
	track[id].p = targetPoint;
	track[id].dir = targetDir;

	Info info = { track[id].k, id };
	temp[track[id].p.first][track[id].p.second] = info;
}

void MoveShark()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			temp[y][x] = b[y][x];
		}
	}

	for (int i = 1; i <= M; i++)
	{
		if (!track[i].isExist) continue;

		int empty = 0; pair<int, int> target; int targetDir = 0;
		for (int m = 1; m <= 4; m++)
		{
			auto p = track[i].p;
			p.first += dirs[m].first; p.second += dirs[m].second;

			if (!BoundaryCheck(p)) continue;

			if (b[p.first][p.second].id == 0)
			{
				empty++;
				target = p;
				targetDir = m;
			}
		}

		if (empty > 1)
		{
			auto preferDirVec = track[i].dirsInfo[track[i].dir];
			targetDir = GetPreferDir(track[i].p, preferDirVec, false);
		}
		else if (empty == 0)
		{
			auto preferDirVec = track[i].dirsInfo[track[i].dir];
			targetDir = GetPreferDir(track[i].p, preferDirVec, true);
		}
		else if (empty == 1)
		{
			if (!CanMove(target, i))
			{
				track[i].isExist = false;
				cnt -= 1;
			}
			else
			{
				Update(i, target, targetDir);
			}
			continue;
		}

		pair<int, int> targetPoint = { track[i].p.first + dirs[targetDir].first, track[i].p.second + dirs[targetDir].second };
		if (!CanMove(targetPoint, i))
		{
			track[i].isExist = false;
			cnt -= 1;
		}
		else
		{
			Update(i, targetPoint, targetDir);
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			b[y][x] = temp[y][x];
		}
	}
}

bool GoalCheck()
{
	if (cnt == 1 && track[1].isExist)
		return true;

	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> k;
	cnt = M;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> b[y][x].id;
			if (b[y][x].id != 0)
			{
				track[b[y][x].id].p = { y,x };
				b[y][x].k = k;
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> track[i].dir;
		b[track[i].p.first][track[i].p.second].id = i;
		track[i].k = k;
	}

	for (int i = 1; i <= M; i++)
	{
		track[i].dirsInfo.resize(5);
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int num = 0; cin >> num;
				track[i].dirsInfo[j].push_back(num);
			}
		}
	}

	int time = 0;
	while (!GoalCheck())
	{
		if (time >= 1000)
		{
			cout << -1;
			return 0;
		}

		MoveShark();
		RemoveSmell();
		time++;
	}

	cout << time;
}