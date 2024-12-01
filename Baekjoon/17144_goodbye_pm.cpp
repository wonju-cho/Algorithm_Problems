#include <iostream>

using namespace std;

#define MAX 57

int b[MAX][MAX];
int temp[MAX][MAX];
int R; int C; 
pair<int, int> movement[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
pair<int, int> counterClockPos = {};
pair<int, int> clockwisekPos = {};

void Diffusion()
{
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			if(b[y][x] > 0)
			{
				int cnt = 0; int cumul = 0; int dust = b[y][x] / 5;
				for(int m = 0; m < 4; m++)
				{
					int dy = y + movement[m].first;
					int dx = x + movement[m].second;

					if(dy >= R || dy < 0 || dx >= C || dx < 0) continue;

					if (b[dy][dx] == -1) continue;

					cnt++;
					cumul += b[dy][dx] / 5;
				}
				temp[y][x] = b[y][x] - dust * cnt + cumul;
			}
			else if(b[y][x] == 0)
			{
				for (int m = 0; m < 4; m++)
				{
					int dy = y + movement[m].first;
					int dx = x + movement[m].second;

					if (dy >= R || dy < 0 || dx >= C || dx < 0) continue;

					if (b[dy][dx] == -1) continue;

					temp[y][x] += b[dy][dx] / 5;
				}
			}
		}
	}

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			if (b[y][x] == -1)
			{
				temp[y][x] = -1;
				continue;
			}
			b[y][x] = temp[y][x];
		}
	}
}

void AirPurifier()
{
	pair<int, int> p1 = counterClockPos;
	pair<int, int> p2 = clockwisekPos;

	for(int i = 0; i < 4; i++)
	{
		p1 = counterClockPos;
		p2 = clockwisekPos;
		if (i == 0) // 1, 5
		{
			for (int x = C - 1; x > p1.second; x--)
			{
				if(b[p1.first][x - 1] == -1)
				{
					temp[p1.first][x] = 0;
					temp[p2.first][x] = 0;
					continue;
				}
				temp[p1.first][x] = b[p1.first][x - 1];
				temp[p2.first][x] = b[p2.first][x - 1];
			}
		}
		else if (i == 1) // 2, 8
		{
			p1.second = C - 1;
			for (int y = 0; y < p1.first; y++)
			{
				temp[y][p1.second] = b[y + 1][p1.second];
			}

			for (int y = p2.first + 1; y < R; y++)
			{
				temp[y][p2.second] = b[y + 1][p2.second];
			}
		}
		else if (i == 2) // 3, 7
		{
			p1.first = 0;
			p2.first = R - 1;
			for (int x = 0; x < C - 1; x++)
			{
				temp[p1.first][x] = b[p1.first][x + 1];
				temp[p2.first][x] = b[p2.first][x + 1];
			}

		}
		else // 4, 6
		{
			//4
			for (int y = p1.first - 1; y > 0; y--)
			{
				temp[y][p1.second] = b[y - 1][p1.second];
			}

			//6
			p2.second = C - 1;
			for (int y = R - 1; y > p2.first; y--)
			{
				temp[y][p2.second] = b[y - 1][p2.second];
			}
		}
	}

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			b[y][x] = temp[y][x];
		}
	}


}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;
	cin >> R >> C >> T;
	bool flag = false;
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			cin >> b[y][x];
			if (b[y][x] == -1 && !flag)
			{
				counterClockPos = { y,x };
				flag = true;
			}
		}
	}
	clockwisekPos = counterClockPos;
	clockwisekPos.first++;

	for(int i = 0; i < T; i++)
	{
		Diffusion();
		AirPurifier();
	}

	int res = 0;
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			if(b[y][x] == -1) continue;
			res += b[y][x];
		}
	}

	cout << res;
}