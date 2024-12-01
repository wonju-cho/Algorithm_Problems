#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
int N = 0;
int board[25][25];
int adj[25][25];
pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

struct Student
{
	pair<int, int> point = { -1,-1 };
	vector<int> favorite = vector<int>(4);
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	unordered_map<int, Student> list;
	int size = N * N;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (y == 0 && x == 0 || y == 0 && x == N - 1 || y == N - 1 && x == 0 || y == N - 1 && x == N - 1)
				adj[y][x] = 2;
			else if (y == 0 || y == N - 1 || x == 0 || x == N-1)
				adj[y][x] = 3;
			else adj[y][x] = 4;
		}
	}

	for (int i = 0; i < size; i++)
	{
		int id = 0; int num1 = 0; int num2 = 0; int num3 = 0; int num4 = 0; cin >> id >> num1 >> num2 >> num3 >> num4;
		list[id].favorite = { num1, num2, num3, num4 };

		int maxBlank = 0;
		int maxFav = -1;
		pair<int, int> seat;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				int favCnt = 0;
				if (board[y][x] != 0) continue;

				//인접한 칸에 좋아하는 학생이 존재하는지
				for(int m = 0; m < 4; m++)
				{
					int dy = y + movement[m].first;
					int dx = x + movement[m].second;

					if (dy >= N || dy < 0 || dx >= N || dx < 0) continue;

					if(find(list[id].favorite.begin(), list[id].favorite.end(), board[dy][dx]) != list[id].favorite.end())
					{
						favCnt++;
					}
				}

				if(favCnt > maxFav)
				{
					maxFav = favCnt;
					seat = { y,x };
					maxBlank = adj[y][x];
				}
				else if(favCnt == maxFav)
				{
					if(adj[y][x] > maxBlank)
					{
						seat = { y,x };
						maxBlank = adj[y][x];
					}
				}
			}
		}
		
		board[seat.first][seat.second] = id;

		for (int m = 0; m < 4; m++)
		{
			int dy = seat.first + movement[m].first;
			int dx = seat.second + movement[m].second;

			if (dy >= N || dy < 0 || dx >= N || dx < 0) continue;

			if (board[dy][dx] != 0) continue;

			adj[dy][dx] -= 1;
		}
	}

	int res = 0;
	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < N; x++)
		{
			int cnt = 0;
			int id = board[y][x];
			for (int m = 0; m < 4; m++)
			{
				int dy = y + movement[m].first;
				int dx = x + movement[m].second;

				if (dy >= N || dy < 0 || dx >= N || dx < 0) continue;

				if (find(list[id].favorite.begin(), list[id].favorite.end(), board[dy][dx]) != list[id].favorite.end())
				{
					cnt++;
				}
			}

			if (cnt == 2)
				res += 10;
			else if (cnt == 3)
				res += 100;
			else if (cnt == 4)
				res += 1000;
			else res += cnt;
		}
	}

	cout << res;
}