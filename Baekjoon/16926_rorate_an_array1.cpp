#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 300
int N; int M; int R;
int board[MAX][MAX];
int temp[MAX][MAX];

void RotateClockwise()
{
	int xLimit = M - 1; int yLimit = N - 1;
	int i = 0;
	while(xLimit > 0 && yLimit > 0)
	{
		int x_ = i; int y_ = i;
		for (int m = 0; m < 4; m++)
		{
			if (m == 0)
			{
				for (int i = 0; i < xLimit; i++, x_++)
				{
					temp[y_][x_] = board[y_][x_ + 1];
				}
			}
			else if (m == 1)
			{
				for (int i = 0; i < yLimit; i++, y_++)
				{
					temp[y_][x_] = board[y_ + 1][x_];
				}
			}
			else if (m == 2)
			{
				for (int i = 0; i < xLimit; i++, x_--)
				{
					temp[y_][x_] = board[y_][x_ - 1];
				}
			}
			else
			{
				for (int i = 0; i < yLimit; i++, y_--)
				{
					temp[y_][x_] = board[y_ - 1][x_];
				}
			}
		}

		yLimit -= 2;
		xLimit -= 2;
		i++;
	}

	for(int y = 0; y < N; y++)
	{
		copy(&temp[y][0], &temp[y][M], &board[y][0]);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> R;
	int start = 0;
	bool isSame = true;

	for (int y = 0; y < N; y++)
	{
		for(int x = 0; x < M; x++)
		{
			if (y == 0 && x == 0) {
				cin >> start;
				board[y][x] = start;
			}
			else
			{
				cin >> board[y][x];
				if (board[y][x] != start)
					isSame = false;
			}
				
		}
	}

	if (isSame || R == M * 2 + (N - 2) * 2)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				cout << board[y][x] << ' ';
			}
			cout << "\n";
		}

		return 0;
	}

	for(int i = 0; i < R; i++)
	{
		RotateClockwise();
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cout << board[y][x] << ' ';
		}
		cout << "\n";
	}
}