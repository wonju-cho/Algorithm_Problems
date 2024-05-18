#include <iostream>

using namespace std;
#define MAX 7
int b[MAX][MAX];
int temp[MAX][MAX];
int res[MAX * MAX][MAX * MAX];

void Rotate90(int N, int i) 
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			temp[x][N - y - 1] = b[y][x];
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			b[y][x] = temp[y][x];
		}
	}

	if (i == 0)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				res[y][x] = b[y][x];
			}
		}
	}
	else if (i == 1)
	{
		for (int y = 0; y < N; y++)
		{
			for (int rx = N, x = 0; rx < N + N; rx++, x++)
			{
				res[y][rx] = b[y][x];
			}
		}

	}
	else {

		for (int y = 0; y < N; y++)
		{
			for (int rx = N*2, x=0; rx < N*2+N; rx++, x++)
			{
				res[y][rx] = b[y][x];
			}
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T = 0; cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cout << '#' << t << '\n';

		int N = 0; cin >> N;

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				cin >> b[y][x];
			}
		}

		for (int i = 0; i < 3; i++)
		{
			Rotate90(N, i);
		}

		int size = N * 3;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < size; x++)
			{
				if (x != 0 && x % N == 0)
				{
					cout << ' ';
				}
				cout << res[y][x];
			}
			cout << "\n";
		}
	}
}