#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 20

struct Group
{
	pair<int, int> p;
	vector<pair<int, int>> points;
	int rainbowCnt = 0;
	int size = -1;
};

struct Cell
{
	int color = 0;
	pair<int, int> p;
};

int N; int M; int score;
int b[MAX][MAX];
int temp[MAX][MAX];
bool v[MAX][MAX];
pair<int, int> dirs[4] = { {-1,0}, {1,0}, {0, -1}, {0,1} };
Group largestGroup;

//검은색 블록은 -1, 무지개 블록은 0으로 표현한다.
//-2는 빈칸으로 설정 <- 내가 설정한거

//블록 그룹은 연결된 블록의 집합이다. 그룹에는 일반 블록이 적어도 하나 있어야 하며, 일반 블록의 색은 모두 같아야 한다.
//검은색 블록은 포함되면 안 되고, 무지개 블록은 얼마나 들어있든 상관없다.
//그룹에 속한 블록의 개수는 2보다 크거나 같아야 하며, 임의의 한 블록에서 그룹에 속한 인접한 칸으로 이동해서 그룹에 속한 다른 모든 칸으로 이동할 수 있어야 한다.
//블록 그룹의 기준 블록은 무지개 블록이 아닌 블록 중에서 행의 번호가 가장 작은 블록, 그러한 블록이 여러개면 열의 번호가 가장 작은 블록이다.


//2. 1에서 찾은 블록 그룹의 모든 블록을 제거한다.블록 그룹에 포함된 블록의 수를 B라고 했을 때, B2점을 획득한다.
//3. 격자에 중력이 작용한다.
//4. 격자가 90도 반시계 방향으로 회전한다.
//5. 다시 격자에 중력이 작용한다.

//격자에 중력이 작용하면 검은색 블록을 제외한 모든 블록이 행의 번호가 큰 칸으로 이동한다. 이동은 다른 블록이나 격자의 경계를 만나기 전까지 계속 된다.

//오늘은 이 게임에 오토 플레이 기능을 만드려고 한다. 오토 플레이는 다음과 같은 과정이 블록 그룹이 존재하는 동안 계속해서 반복되어야 한다.

void ApplyGravity()
{
	for (int x = 0; x < N; x++)
	{
		for (int y = N - 1; y >= 0; y--)
		{
			if (b[y][x] == -1 || b[y][x] != -2) continue;

			int targetY = y; bool flag = false;
			while (b[targetY][x] == -2) {
				targetY--;
			}

			if (targetY < 0 || b[targetY][x] == -1 || b[targetY][x] == -2)
				continue;

			b[y][x] = b[targetY][x];
			b[targetY][x] = -2;
		}
	}
}

void Rotate90CounterClockwise()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			temp[N - 1 - x][y] = b[y][x];
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

void Update(int bSize, pair<int, int> p, int rCnt, vector<pair<int, int>>& points)
{
	largestGroup.size = bSize;
	largestGroup.p = p;
	largestGroup.rainbowCnt = rCnt;
	largestGroup.points = points;
}

void Initialize()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			v[y][x] = false;
		}
	}
}

bool BoundaryCheck(pair<int, int> p)
{
	if (p.first < 0 || p.first >= N || p.second < 0 || p.second >= N) return false;

	return true;
}

void BFS(pair<int, int> p)
{
	int color = b[p.first][p.second]; int rCnt = 0; vector<pair<int, int>> points;
	points.push_back(p);
	queue<pair<Cell, int>> q;
	q.push({ {color, p}, 0 });
	v[p.first][p.second] = true;

	while (!q.empty())
	{
		auto curr = q.front().first;
		auto size = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> tempP = { curr.p.first + dirs[i].first, curr.p.second + dirs[i].second };

			if (!BoundaryCheck(tempP)) continue;

			if (v[tempP.first][tempP.second] || b[tempP.first][tempP.second] == -2) continue;

			if (b[tempP.first][tempP.second] == curr.color || b[tempP.first][tempP.second] == 0)
			{
				if (b[tempP.first][tempP.second] == 0)
					rCnt++;

				v[tempP.first][tempP.second] = true;
				q.push({ { color, tempP}, size + 1 });
				points.push_back(tempP);
			}
		}
	}

	int bSize = points.size();
	for (int i = 0; i < bSize; i++)
	{
		if (b[points[i].first][points[i].second] == 0)
		{
			v[points[i].first][points[i].second] = false;
		}
	}

	if (bSize < 2)
	{
		return;
	}

	//그러한 블록 그룹이 여러 개라면 포함된 무지개 블록의 수가 가장 많은 블록 그룹, 그러한 블록도 여러개라면 기준 블록의 행이 가장 큰 것을, 그 것도 여러개이면 열이 가장 큰 것을 찾는다.

	//1. 크기가 가장 큰 블록 그룹을 찾는다.
	if (largestGroup.size < bSize)
	{
		Update(bSize, p, rCnt, points);
	}
	else if (largestGroup.size == bSize)
	{
		//그러한 블록 그룹이 여러 개라면 포함된 무지개 블록의 수가 가장 많은 블록 그룹
		if (rCnt > largestGroup.rainbowCnt)
		{
			Update(bSize, p, rCnt, points);
		}
		else if (rCnt == largestGroup.rainbowCnt)
		{
			if (largestGroup.p.first < p.first) //그러한 블록도 여러개라면 기준 블록의 행이 가장 큰 것을,
			{
				Update(bSize, p, rCnt, points);
			}
			else if (largestGroup.p.first == p.first)
			{
				if (largestGroup.p.second < p.second) // 그것도 여러개이면 열이 가장 큰 것을 찾는다.
				{
					Update(bSize, p, rCnt, points);
				}
			}
		}
	}
}

void RemoveGroup()
{
	score += largestGroup.points.size() * largestGroup.points.size();
	for (int i = 0; i < largestGroup.points.size(); i++)
	{
		auto p = largestGroup.points[i];
		b[p.first][p.second] = -2;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> b[y][x];
		}
	}

	do
	{
		largestGroup.size = -1;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (b[y][x] == 0 || b[y][x] == -1 || b[y][x] == -2) continue;

				if (!v[y][x])
				{
					BFS({ y,x });
				}
			}
		}

		if (largestGroup.size == -1)
		{
			break;
		}

		RemoveGroup();

		ApplyGravity();
		Rotate90CounterClockwise();
		ApplyGravity();
		Initialize();

	} while (largestGroup.size >= 2);

	cout << score;
}