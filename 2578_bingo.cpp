#include <iostream>
#include <unordered_map>

using namespace std;
int board[5][5];
unordered_map<int, pair<int, int>> umBoard;

int BingoCheck()
{
	int res = 0;
	//y check
	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		cnt = 0;
		for(int y = 0; y < 5; y++)
		{
			if (board[y][i] == -1)
			{
				cnt++;
			}
		}

		if (cnt >= 5)
			res++;
	}

	//x check
	for (int i = 0; i < 5; i++)
	{
		cnt = 0;
		for (int x = 0; x < 5; x++)
		{
			if (board[i][x] == -1)
			{
				cnt++;
			}
		}

		if (cnt >= 5)
			res++;
	}

	//diagonal check
	cnt = 0;
	pair<int, int> temp = { 0,0 };
	for (int i = 0; i < 5; i++, temp.first++, temp.second++)
	{
		if (board[temp.first][temp.second] == -1)
		{
			cnt++;
		}
	}
	if (cnt >= 5)
		res++;

	cnt = 0;
	temp = { 0,4 };
	for (int i = 0; i < 5; i++, temp.first++, temp.second--)
	{
		if (board[temp.first][temp.second] == -1)
		{
			cnt++;
		}
	}

	if (cnt >= 5)
		res++;

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			int num = 0; cin >> num;
			board[y][x] = num;
			umBoard[num] = { y,x };
		}
	}

	int cnt = 1;
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++, cnt++)
		{
			int num = 0; cin >> num;
			pair<int, int> point = umBoard[num];
			board[point.first][point.second] = -1;

			if (cnt >= 5)
			{
				if(BingoCheck() >= 3)
				{
					cout << cnt;
					return 0;
				}
			}
		}
	}
}