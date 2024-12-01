#include <iostream>

using namespace std;
int board[19][19];
//for avoiding counting pieces that were placed sequentially over 6
bool leftDiaV[19][19];	//y++, x--
bool rightDiaV[19][19]; //y++, x++
bool rowV[19][19];		//x++
bool columnV[19][19];	//y++
pair<int, int> res;

int Check(int num, int y_, int x_)
{
	int cnt = 0;
	pair<int, int> temp{ y_, x_ };
	//right diagonal
	while(board[temp.first][temp.second] == num && !rightDiaV[temp.first][temp.second])
	{
		if (temp.first >= 19 || temp.first < 0 || temp.second >= 19 || temp.second < 0) break;

		if (board[temp.first][temp.second] == num)
			cnt++;

		temp.first++; temp.second++;
	}

	if (cnt >= 6)
	{
		--temp.first; --temp.second;
		while (cnt > 0)
		{
			rightDiaV[temp.first][temp.second] = true;
			temp.first--; temp.second--; cnt--;
		}
	}
	else if (cnt == 5)
	{
		res = { y_ + 1, x_ + 1 };
		return true;
	}

	cnt = 0;
	temp = { y_, x_ };
	//left diagonal
	while (board[temp.first][temp.second] == num && !leftDiaV[temp.first][temp.second])
	{
		if (temp.first >= 19 || temp.first < 0 || temp.second >= 19 || temp.second < 0) break;

		if (board[temp.first][temp.second] == num)
			cnt++;

		temp.first++; temp.second--;
	}

	if (cnt >= 6)
	{
		temp.first--; temp.second++;
		while (cnt > 0)
		{
			leftDiaV[temp.first][temp.second] = true;
			temp.first--; temp.second++; cnt--;
		}
	}
	else if (cnt == 5)
	{
		temp.first--; temp.second++;
		res = { temp.first + 1, temp.second + 1};
		return true;
	}

	cnt = 0;
	temp = { y_, x_ };
	//row
	while (board[temp.first][temp.second] == num && !rowV[temp.first][temp.second])
	{
		if (temp.first >= 19 || temp.first < 0 || temp.second >= 19 || temp.second < 0) break;

		if (board[temp.first][temp.second] == num)
			cnt++;

		temp.second++;
	}

	if (cnt >= 6)
	{
		--temp.second;
		while (cnt > 0)
		{
			rowV[temp.first][temp.second] = true;
			temp.second--; cnt--;
		}
	}
	else if (cnt == 5)
	{
		res = { y_ + 1, x_ + 1 };
		return true;
	}

	cnt = 0;
	temp = { y_, x_ };
	//column
	while (board[temp.first][temp.second] == num && !columnV[temp.first][temp.second])
	{
		if (temp.first >= 19 || temp.first < 0 || temp.second >= 19 || temp.second < 0) break;

		if (board[temp.first][temp.second] == num)
			cnt++;

		temp.first++;
	}

	if (cnt >= 6)
	{
		--temp.first;
		while (cnt > 0)
		{
			columnV[temp.first][temp.second] = true;
			temp.first--; cnt--;
		}
	}
	else if (cnt == 5)
	{
		res = { y_ + 1, x_ + 1 };
		return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int y = 0; y < 19; y++)
	{
		for(int x = 0; x < 19; x++)
		{
			int temp = 0; cin >> temp;
			board[y][x] = temp;
		}
	}

	bool isWinnerExist = false;
	for (int y = 0; y < 19; y++)
	{
		for (int x = 0; x < 19; x++)
		{
			if (board[y][x] == 1 || board[y][x] == 2)
			{
				if (Check(board[y][x], y, x))
				{
					cout << board[y][x] << "\n";
					cout << res.first << ' ' << res.second;
					isWinnerExist = true;
					return 0;
				}
			}
		}
	}

	if (!isWinnerExist)
		cout << 0;
}