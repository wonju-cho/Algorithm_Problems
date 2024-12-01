#include <iostream>

using namespace std;
#define MAX 6561
int N;
char board[MAX][MAX];

void MarkStar(int n, int y_, int x_)
{
	if(n == 3)
	{
		for(int y = y_; y < y_ + n; y++)
		{
			for(int x = x_; x < x_ + n; x++)
			{
				if(y == y_ + 1 && x == x_ + 1) continue;
				board[y][x] = '*';
			}
		}
		return ;
	}

	MarkStar(n / 3, y_, x_);
	MarkStar(n / 3, y_, x_ + n / 3);
	MarkStar(n / 3, y_, x_ + n / 3 * 2);

	MarkStar(n / 3, y_ + n / 3, x_);
	MarkStar(n / 3, y_ + n / 3, x_ + n / 3 * 2);

	MarkStar(n / 3, y_ + n / 3 * 2, x_ );
	MarkStar(n / 3, y_ + n / 3 * 2, x_ + n / 3);
	MarkStar(n / 3, y_ + n / 3 * 2, x_ + n / 3 * 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			board[y][x] = ' ';
		}
	}

	MarkStar(N, 0 ,0);

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << board[y][x];
		}
		cout << "\n";
	}
}