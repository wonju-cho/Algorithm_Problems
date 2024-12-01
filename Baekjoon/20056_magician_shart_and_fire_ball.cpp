#include <iostream>
#include <vector>

using namespace std;
struct FireBall
{
	pair<int, int> pos;
	int m = 0;
	int s = 0;
	int dir;
};

#define MAX 54
vector<FireBall> b[MAX][MAX];
vector<FireBall> currFB;
int N; int C;
pair<int, int> movement[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

void MoveFireBall()
{
	for (auto fb : currFB)
	{
		b[fb.pos.first][fb.pos.second].clear();
	}

	for(auto fb : currFB)
	{
		pair<int, int> s = { movement[fb.dir].first * fb.s % N, movement[fb.dir].second * fb.s % N };
		int dy = fb.pos.first + s.first;
		int dx = fb.pos.second + s.second;

		if (dy < 0) dy += N;
		else if (dy >= N) dy -= N;
		if (dx < 0) dx += N;
		else if (dx >= N) dx -= N;

		fb.pos = { dy,dx };
		b[dy][dx].push_back(fb);
	}
}

void MergeFireBalls()
{
	currFB.clear();

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if(b[y][x].size() > 1)
			{
				int m = 0; int s = 0; bool isEven = true; bool isOdd = true;
				for(auto fb : b[y][x])
				{
					if (fb.dir % 2 == 1) isEven = false; //홀수
					else isOdd = false;
					m += fb.m;
					s += fb.s;
				}

				//나누어질 파이어볼 질량 속도 방향
				m /= 5;
				if (m == 0) //사라짐
				{
					b[y][x].clear();
					continue;
				}

				s = s / b[y][x].size();

				b[y][x].clear();
				if(isEven || isOdd) //0,2,4,6
				{
					FireBall f1 = { {y,x}, m, s, 0};
					FireBall f2 = { {y,x}, m, s, 2};
					FireBall f3 = { {y,x}, m, s, 4};
					FireBall f4 = { {y,x}, m, s, 6};

					currFB.push_back(f1);
					currFB.push_back(f2);
					currFB.push_back(f3);
					currFB.push_back(f4);

					b[y][x].push_back(f1);
					b[y][x].push_back(f2);
					b[y][x].push_back(f3);
					b[y][x].push_back(f4);
				}
				else //1,3,5,7
				{
					FireBall f1 = { {y,x}, m, s, 1 };
					FireBall f2 = { {y,x}, m, s, 3 };
					FireBall f3 = { {y,x}, m, s, 5 };
					FireBall f4 = { {y,x}, m, s, 7 };

					currFB.push_back(f1);
					currFB.push_back(f2);
					currFB.push_back(f3);
					currFB.push_back(f4);

					b[y][x].push_back(f1);
					b[y][x].push_back(f2);
					b[y][x].push_back(f3);
					b[y][x].push_back(f4);
				}
			}
			else if(b[y][x].size() == 1)
			{
				currFB.push_back(b[y][x][0]);
			}
		}
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K = 0; int M = 0;
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++)
	{
		int r; int c; int m; int s; int dir; cin >> r >> c >> m >> s >> dir;
		FireBall fb = { { r-1,c-1 }, m, s, dir };
		currFB.push_back(fb);
		b[r-1][c-1].push_back(fb);
	}

	for(int k = 0; k < K; k++)
	{
		MoveFireBall();
		MergeFireBalls();
	}

	int res = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (!b[y][x].empty())
			{
				for(auto fb : b[y][x])
				{
					res += fb.m;
				}
			}
		}
	}

	cout << res;
}