#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 50

//위, 아래, 왼, 오
pair<int, int> blizzard[4] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
//서,남,동,북
pair<int, int> movement[4] = { {0,-1}, {1,0}, {0,1}, {-1,0} };

//구슬 정보 저장
int board[MAX][MAX];
vector<int> marbles;

int N = 0; int M = 0;
int res = 0;
pair<int, int> sharkPos;

void GetAllMarbles()
{
	marbles.clear();

	int moveDist = 1;
	int id = 1;
	pair<int, int> p = sharkPos;
	int dir = 0;
	bool flag = false;
	while(1)
	{
		if (flag)
			break;

		for (int i = 0; i < 2; i++)
		{
			for(int md = 0; md < moveDist; md++, id++)
			{
				if (id == N * N)
				{
					flag = true;
					break;
				}

				p.first += movement[dir].first;
				p.second += movement[dir].second;
				
				if (board[p.first][p.second] > 0)
					marbles.push_back(board[p.first][p.second]);
			}
			dir = (dir + 1) % 4;
		}

		moveDist++;
	}
}

void Magic(int dir, int s)
{
	auto p = sharkPos;
	for(int i = 0; i < s; i++)
	{
		p.first += blizzard[dir].first;
		p.second += blizzard[dir].second;

		if(p.first < 0 || p.first >= N || p.second < 0 || p.second >= N)
			continue;

		board[p.first][p.second] = 0;
	}
}

void ExplodeMarble()
{
	GetAllMarbles();

	bool flag = false;
	while(true)
	{
		flag = false;

		for (int i = 0; i < marbles.size(); i++)
		{
			int cnt = 0;
			int s = marbles[i];
			int idx = i;

			if (idx + 1 >= marbles.size())
				break;

			int e = marbles[idx + 1];
			while (s == e)
			{
				if (s == e)
					cnt++;

				if (++idx >= marbles.size())
					break;

				e = marbles[idx];
			}

			if (cnt >= 4)
			{
				marbles.erase(marbles.begin() + i, marbles.begin() + idx);

				if (s == 2)
					res += 2 * cnt;
				else if (s == 3)
					res += 3 * cnt;
				else res += cnt;

				i--;
				flag = true;
			}

		}

		if (!flag)
			break;
	}
}

void SetBoard(vector<int>& m)
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			board[y][x] = 0;
		}
	}

	int moveDist = 1;
	pair<int, int> p = sharkPos;
	int dir = 0;
	bool flag = false;
	int idx = 0;
	int mSize = m.size();

	while (1)
	{
		if (flag)
			break;

		for (int i = 0; i < 2; i++)
		{
			for (int md = 0; md < moveDist; md++, idx++)
			{
				if (idx == N * N || idx >= mSize)
				{
					flag = true;
					break;
				}

				p.first += movement[dir].first;
				p.second += movement[dir].second;

				board[p.first][p.second] = m[idx];
			}
			dir = (dir + 1) % 4;
		}

		moveDist++;
	}
}

void Transformation()
{
	vector<int> temp;
	for (int i = 0; i < marbles.size(); i++)
	{
		int A = 1;
		int B = marbles[i];
		int idx = i + 1;

		if (idx >= marbles.size())
		{
			temp.push_back(A);
			temp.push_back(B);
			break;
		}

		int e = marbles[idx];
		while (B == e)
		{
			if (B == e)
				A++;

			if (++idx >= marbles.size())
				break;

			e = marbles[idx];
		}

		temp.push_back(A);
		temp.push_back(B);
		
		i = idx - 1;
	}

	SetBoard(temp);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N; cin >> M;
	sharkPos = { N / 2, N / 2 };

	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < N; x++)
		{
			int temp = 0; cin >> temp;
			board[y][x] = temp;
		}
	}

	int dir = 0; int s = 0;

	//블리자드
	//-> 폭발(4개이상 연속하는 구슬이 존재 하지 않을 때 까지)
	//-> 변환
	for(int m = 0; m < M; m++)
	{
		cin >> dir; cin >> s;
		dir -= 1;
		Magic(dir, s);
		ExplodeMarble();
		Transformation();
	}

	cout << res;
}