#include <iostream>

using namespace std;
#define MAX 64
int N;
int board[MAX][MAX];

void QuadTree(int n, int y_, int x_)
{
	if(n == 1)
	{
		cout << board[y_][x_];
		return;
	}

	int val = board[y_][x_];
	bool isSame = true;
	for (int y = y_; y < y_ + n; y++)
	{
		for (int x = x_; x < x_ + n; x++)
		{
			if(board[y][x] != val)
			{
				isSame = false;
				break;
			}
		}
		if (!isSame) break;
	}

	//recursion divided into 4 pieces
	if(!isSame)
	{
		cout << '(';
		QuadTree(n / 2, y_, x_);
		QuadTree(n / 2, y_, x_ + n / 2);
		QuadTree(n / 2, y_ + n / 2, x_);
		QuadTree(n / 2, y_ + n / 2, x_ + n / 2);
		cout << ')';
	}
	else
	{
		cout << val;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int y = 0; y < N; y++)
	{
		string str; cin >> str;
		for (int x = 0; x < N; x++)
		{
			board[y][x] = str[x] - '0';
		}
	}

	QuadTree(N, 0, 0);
}