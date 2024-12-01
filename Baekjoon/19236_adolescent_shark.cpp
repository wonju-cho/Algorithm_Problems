#include <iostream>
#include <algorithm>

using namespace std;

struct Fish {
	pair<int, int> p;
	int dir;
	bool isAlive = true;
};

int res = 0;
Fish track[17];
int b[4][4];

pair<int, int> dirs[8] = { {-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1,0}, {1, 1}, {0,1}, {-1,1} };

bool BoundaryCheck(pair<int, int> p)
{
	if (p.first >= 4 || p.first < 0 || p.second >= 4 || p.second < 0)
		return false;

	return true;
}

bool IsSafe(pair<int, int> p, pair<int, int> shark)
{
	if (!BoundaryCheck(p)) return false;

	if (shark.first == p.first && shark.second == p.second)
		return false;

	return true;
}

void Clear(pair<int, int> p, int id) {
	b[p.first][p.second] = -1;
	track[id].isAlive = false;
}

void MoveFish(pair<int, int> shark) {

	for (int i = 1; i <= 16; i++)
	{
		auto pos = track[i].p;
		if (b[pos.first][pos.second] == -1 || !track[i].isAlive) {
			continue;
		}

		//dir idx
		int idx = track[i].dir;
		pair<int, int> targetPos = { pos.first + dirs[idx].first, pos.second + dirs[idx].second };

		while (!IsSafe(targetPos, shark))
		{
			idx = (idx + 1) % 8;
			targetPos.first = pos.first + dirs[idx].first; targetPos.second = pos.second + dirs[idx].second;
		}

		track[i].dir = idx;
		swap(b[pos.first][pos.second], b[targetPos.first][targetPos.second]);
		if(b[pos.first][pos.second] != -1)
			track[b[pos.first][pos.second]].p = { pos.first, pos.second };
		if(b[targetPos.first][targetPos.second] != -1)
			track[b[targetPos.first][targetPos.second]].p = { targetPos.first, targetPos.second };
	}
}

void CopyData(int(&original)[4][4], int(&temp)[4][4], Fish(&originalT)[17], Fish(&tempT)[17]) {

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			temp[y][x] = original[y][x];
		}
	}

	for (int i = 1; i <= 16; i++)
	{
		tempT[i] = originalT[i];
	}
}


void MoveShark(pair<int, int> p, int dir, int cnt) {

	res = max(cnt, res);

	//이동하기 전 모습 복구하려고 만들어 놓는것
	int temp[4][4]; Fish tempTrack[17];
	CopyData(b, temp, track, tempTrack);

	MoveFish(p);

	pair<int, int> nextPos = p;
	while (true)
	{
		nextPos.first += dirs[dir].first; nextPos.second += dirs[dir].second;

		if (!BoundaryCheck(nextPos)) break;
		//갈수 없는 방향인지 체크
		if (b[nextPos.first][nextPos.second] == -1) continue;

		int idx = b[nextPos.first][nextPos.second];
		auto info = track[idx];

		Clear(nextPos, idx);

		MoveShark(nextPos, info.dir, cnt + idx);

		b[nextPos.first][nextPos.second] = idx;
		track[idx].isAlive = true;
	}

	CopyData(temp, b, tempTrack, track);

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			//번호
			cin >> b[y][x];
			track[b[y][x]].p = { y,x };
			cin >> track[b[y][x]].dir;
			track[b[y][x]].dir -= 1;
		}
	}

	//fish: p, dir, isAlive
	//map: id만
	int id = b[0][0];
	int dir = track[id].dir;

	//죽음
	Clear({ 0,0 }, id);
	
	//p, dir, cnt
	MoveShark({ 0,0 }, dir, id);

	cout << res;
}