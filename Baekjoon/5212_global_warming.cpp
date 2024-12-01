#include <iostream>

using namespace std;
#define MAX 11
int R; int C;

char b[MAX][MAX];
char temp[MAX][MAX];

pair<int, int> dirs[4] = { {-1,0}, {1,0}, {0,1}, {0,-1} };

void MapUpdate() {

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			temp[y][x] = b[y][x];
		}
	}

	//x = land | . = sea
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			if (b[y][x] == '.') continue;

			int cnt = 0;

			for (int i = 0; i < 4; i++)
			{
				pair<int, int> p = { y + dirs[i].first, x + dirs[i].second };

				if (b[p.first][p.second] == 'X') continue;

				if (p.first >= R || p.first < 0 || p.second >= C || p.second < 0) {
					cnt++;
				}
				else if (b[p.first][p.second] == '.')
					cnt++;
			}

			if (cnt == 3 || cnt == 4)
			{
				temp[y][x] = '.';
			}
		}
	}

	int sx = 10; int ex = 0; int sy = 0; int ey = 0;
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			if (temp[y][x] != 'X') continue;

			if (ey < y) ey = y;

			if (sx > x)
			{
				if (sx == 10) sy = y;
				sx = x;
			}

			if (ex < x) ex = x;
		}
	}

	if (sx == 10) return;

	for (int y = sy; y <= ey; y++)
	{
		for (int x = sx; x <= ex; x++)
		{
			cout << temp[y][x];
		}
		cout << "\n";
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int y = 0; y < R; y++)
	{
		string str; cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			b[y][i] = str[i];
		}
	}

	MapUpdate();

}