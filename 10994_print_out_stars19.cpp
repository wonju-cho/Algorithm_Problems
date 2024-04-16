#include<iostream>

using namespace std;

int N;
int largest;

#define MAX 398
char board[MAX][MAX];

void Draw(int n)
{
	pair<int, int> start{0,0};
	int length = 1 + 4 * (n - 1);

	if(n == 1)
	{
		board[largest / 2][largest / 2] = '*';
		return;
	}
	else if (n != N)
	{
		start = { 0,0 };
		while (n != N)
		{
			start.first += 2;
			start.second += 2;
			n++;
		}
	}

	//x
	pair<int, int> xTemp = { start.first + length - 1, start.second };
	pair<int, int> startTemp = start;
	for (int i = 0; i < length; i++, startTemp.second++, xTemp.second++)
	{
		board[startTemp.first][startTemp.second] = '*';
		board[xTemp.first][xTemp.second] = '*';
	}

	//y
	pair<int, int> yTemp = {start.first, start.second + length - 1};
	for (int i = 0; i < length; i++, start.first++, yTemp.first++)
	{
		board[start.first][start.second] = '*';
		board[yTemp.first][yTemp.second] = '*';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int n = N;
	largest = 1 + 4 * (n - 1);
	for (int i = 0; i < largest; i++)
	{
		for (int j = 0; j < largest; j++)
		{
			board[i][j] = ' ';
		}
	}
	
	for(int i = n; i > 0; i--)
	{
		Draw(i);
	}

	for(int i = 0; i < largest; i++)
	{
		for(int j = 0; j < largest; j++)
		{
			cout<<board[i][j];
		}
		cout << "\n";
	}
}