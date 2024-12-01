#include <iostream>

using namespace std;
#define MAX 500

int N;
int board[MAX][MAX];
int res[MAX][MAX];

void Initialize()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			board[y][x] = res[y][x];
		}
	}
}

void RotateClockwise45Degree(int n_)
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			res[y][x] = board[y][x];
		}
	}

	for(int n = 0; n < n_; n++)
	{
		//main diagonal
		pair<int, int> start{ 0, 0 };
		pair<int, int> target{ 0, N / 2 };
		for (int i = 0; i < N; i++, start.first++, start.second++, target.first++)
		{
			res[target.first][target.second] = board[start.first][start.second];
		}

		//middle column
		start = { 0, N / 2 };
		target = { 0, N - 1 };
		for (int i = 0; i < N; i++, start.first++, target.first++, target.second--)
		{
			res[target.first][target.second] = board[start.first][start.second];
		}

		//middle row
		start = { N / 2, 0 };
		target = { 0, 0 };
		for (int i = 0; i < N; i++, start.second++, target.first++, target.second++)
		{
			res[target.first][target.second] = board[start.first][start.second];
		}

		//anti-diagonal matrix
		start = { 0, N - 1 };
		target = { N / 2, N - 1 };
		for (int i = 0; i < N; i++, start.first++, start.second--, target.second--)
		{
			res[target.first][target.second] = board[start.first][start.second];
		}
		Initialize();
	}
}

void RotateCounterClockwise45Degree(int n_)
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			res[y][x] = board[y][x];
		}
	}

	for (int n = 0; n < n_; n++)
	{
		//main diagonal
		pair<int, int> start{ 0,0 };
		pair<int, int> target{ N / 2, 0};
		for (int i = 0; i < N; i++, start.first++, start.second++, target.second++)
		{
			res[target.first][target.second] = board[start.first][start.second];
		}

		//middle column
		start = { 0, N / 2 };
		target = { 0, 0 };
		for (int i = 0; i < N; i++, start.first++, target.first++, target.second++)
		{
			res[target.first][target.second] = board[start.first][start.second];
		}

		//middle row
		start = { N / 2, 0 };
		target = { N - 1, 0 };
		for (int i = 0; i < N; i++, start.second++, target.first--, target.second++)
		{
			res[target.first][target.second] = board[start.first][start.second];
		}

		//anti-diagonal matrix
		start = { 0, N - 1 };
		target = { 0, N / 2 };
		for (int i = 0; i < N; i++, start.first++, start.second--, target.first++)
		{
			res[target.first][target.second] = board[start.first][start.second];
		}

		Initialize();
	}

}

void PrintBoard(int n)
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << board[y][x] <<' ';
		}
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0; cin >> T;

	for(int t = 0; t < T; t++)
	{
		int degree = 0; cin >> N; cin >> degree;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				int temp = 0; cin >> temp;
				board[y][x] = temp;
			}
		}

		int n = degree / 45;
		if (degree == 360 || degree == -360)
		{
			PrintBoard(N);
			continue;
		}

		if (n > 4)
		{
			RotateCounterClockwise45Degree(abs((degree - 360) / 45));
		}
		else if (n < -4)
		{
			RotateClockwise45Degree((360 + degree) / 45);
		}
		else if(n > 0 && n < 4)
		{
			RotateClockwise45Degree(n);
		}
		else
		{
			RotateCounterClockwise45Degree(abs(n));
		}
		PrintBoard(N);
	}
}