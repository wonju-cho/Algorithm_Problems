#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
#define MAX 64
int N;
int mSize;
int b[MAX][MAX];
bool v[MAX][MAX];
pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,-1}, {0,1} };
int largest = 0;

void RotateArray(vector<vector<int>>& vec, pair<int,int> s, int l, int cy)
{
	const int size = vec.size();
	vector<vector<int>> t(size, vector<int>(size));

	for(int y = 0; y < size; y++)
	{
		for(int x = 0; x < size; x++)
		{
			t[x][size - 1 - y] = vec[y][x];
		}
	}

	s.first = cy; int currX = s.second;
	for(int y = 0; y < l; y++, s.first++)
	{
		for(int x = 0; x < l; x++, s.second++)
		{
			b[s.first][s.second] = t[y][x];
		}
		s.second = currX;
	}
}

void FireStorm(int L)
{
	/*
	 * 파이어스톰을 시전하려면 시전할 때마다 단계 L을 결정해야 한다.파이어스톰은 먼저 격자를 2L × 2L 크기의 부분 격자로 나눈다.
	 * 그 후, 모든 부분 격자를 시계 방향으로 90도 회전시킨다.
	 */

	if (L == 0) return;

	int len = pow(2, L); int lenSquare = len * len;
	int subSize = (mSize * mSize) / lenSquare;
	int limit = subSize / lenSquare;
	pair<int, int> curr = { 0,0 };
	int currY = 0;
	for(int i = 0 ; i < subSize; i++)
	{
		if (curr.second >= mSize)
		{
			curr.first += len;
			curr.second = 0;
			currY += len;
		}

		pair<int, int> p = curr;
		vector<vector<int>> vec(len, vector<int>(len));
		for(int y = 0; y < len; y++, curr.first++)
		{
			for(int x = 0; x < len; x++, curr.second++)
			{
				vec[y][x] = b[curr.first][curr.second];
			}
			curr.second = p.second;
		}

		RotateArray(vec, curr, len, currY);

		curr.second += len;
		curr.first = currY;
	}
}

void Melting()
{
	/*
	 * 이후 얼음이 있는 칸 3개 또는 그 이상과 인접해있지 않은 칸은 얼음의 양이 1 줄어든다.
	 * (r, c)와 인접한 칸은(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)이다.
	 */
	vector<pair<int, int>> melted;
	for (int y = 0; y < mSize; y++)
	{
		for (int x = 0; x < mSize; x++)
		{
			int cnt = 0;
			for (int m = 0; m < 4; m++)
			{
				int dy = y + movement[m].first;
				int dx = x + movement[m].second;

				if (dy < 0 || dy >= mSize || dx < 0 || dx >= mSize) continue;

				if(b[dy][dx] > 0)
				{
					cnt++;
				}
			}

			if (cnt < 3)
				melted.push_back({ y,x });
		}
	}

	for(auto m : melted)
	{
		b[m.first][m.second] -= 1;
	}
}

void BFS(pair<int,int> p)
{
	queue<pair<int, int>> q;
	q.push(p);
	v[p.first][p.second] = true;
	int res = 1;

	while(!q.empty())
	{
		auto pos = q.front();
		q.pop();

		for (int m = 0; m < 4; m++)
		{
			int dy = pos.first + movement[m].first;
			int dx = pos.second + movement[m].second;

			if (dy < 0 || dy >= mSize || dx < 0 || dx >= mSize) continue;

			if (v[dy][dx]) continue;

			if(b[dy][dx] > 0)
			{
				v[dy][dx] = true;
				res++;
				q.push({dy,dx});
			}
		}
	}

	if (largest < res) largest = res;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q;
	cin >> N; cin >> Q;
	mSize = pow(2, N);

	for(int y = 0; y < mSize; y++)
	{
		for(int x = 0; x < mSize; x++)
		{
			cin >> b[y][x];
		}
	}

	for(int q = 0; q < Q; q++)
	{
		int L = 0; cin >> L;
		FireStorm(L);
		Melting();
	}

	//남아있는 얼음 A[r][c]의 합
	//남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
	int sum = 0;
	for (int y = 0; y < mSize; y++)
	{
		for (int x = 0; x < mSize; x++)
		{
			if (!v[y][x] && b[y][x] > 0)
				BFS({ y,x });

			if(b[y][x] > 0)
				sum += b[y][x];
		}
	}

	cout << sum << "\n" << largest;
}