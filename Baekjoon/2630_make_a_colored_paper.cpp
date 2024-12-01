#include <iostream>

using namespace std;
int board[128][128];
int res[2];
int N;

void CountColoredPaper(int n, int y_, int x_)
{
	if(n == 1)
	{
		res[board[y_][x_]]++;
		return ;
	}

	int num = board[y_][x_];
	bool isSame = true;
	for(int y = y_; y < y_ + n; y++)
	{
		for(int x = x_; x < x_ + n; x++)
		{
			if(board[y][x] != num)
			{
				isSame = false;
				break;
			}
		}
		if (!isSame) break;
	}

	//divide into 4 pieces
	if(!isSame)
	{
		CountColoredPaper(n / 2, y_, x_);
		CountColoredPaper(n / 2, y_, x_ + n / 2);
		CountColoredPaper(n / 2, y_ + n / 2, x_);
		CountColoredPaper(n / 2, y_ + n / 2, x_ + n / 2);
	}
	else
	{
		res[num]++;
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
		for (int x = 0; x < N; x++)
		{
			int temp = 0; cin >> temp;
			board[y][x] = temp;
		}
	}

	CountColoredPaper(N, 0, 0);

	cout << res[0]<<"\n";
	cout << res[1];
}
