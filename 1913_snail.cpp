#include <iostream>

using namespace std;

#define MAX 999

int board[MAX][MAX];
pair<int, int> movement[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N; int target; cin >> N; cin >> target;

	int num = 1;
	int size = N * N;
	int moveIdx = 0;
	pair<int, int> startPos = { N / 2, N / 2 };
	board[startPos.first][startPos.second] = num;
	int distance = 1;
	while(num < size)
	{
		for (int i = 0; i < distance; i++)
		{
			num++;

			if (num > size) break;

			int dy = startPos.first + movement[moveIdx].first;
			int dx = startPos.second + movement[moveIdx].second;
			board[dy][dx] = num;
			startPos = { dy,dx };
		}

		moveIdx = (moveIdx + 1) % 4;
		if (moveIdx % 2 == 0) distance++;
	}

	pair<int, int> targetPos;
	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < N; x++)
		{
			if (board[y][x] == target) targetPos = { y,x };
			cout << board[y][x] << " ";
		}
		cout << "\n";
	}
	cout << targetPos.first + 1 << " " << targetPos.second + 1;
}