#include<iostream>
#include<queue>

using namespace std;

int W;
int H;
int sW;
int sH;
int fR;
int fC;

int board[1002][1002];
bool v[1002][1002];

pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

struct Square
{
	pair<int, int> point;
	int cnt = 0;
};

bool CanMove(pair<int,int> p, int dir)
{
	if(dir == 0) //down
	{
		auto point = p;
		point.first += sH - 1;
		if (point.first >= H) 
			return false;
		for(int x = 0; x < sW; x++)
		{
			if (board[point.first][point.second + x] == 1)
				return false;
		}
	}
	else if(dir == 1) //up
	{
		for(int x = 0 ; x < sW; x++)
		{
			if (board[p.first][p.second + x] == 1)
				return false;
		}
	}
	else if(dir == 2) //right
	{
		auto point = p;
		point.second += sW - 1;
		if(point.second >= W) 
			return false;
		for(int y = 0; y < sH; y++)
		{
			if (board[point.first + y][point.second] == 1)
				return false;
		}
	}
	else //left
	{
		for (int y = 0; y < sH; y++)
		{
			if (board[p.first + y][p.second] == 1)
				return false;
		}
	}

	return true;
}


int BFS(pair<int,int> s)
{
	queue<Square> q;
	q.push({s});

	while(!q.empty())
	{
		auto point = q.front().point;
		int cnt = q.front().cnt;
		q.pop();

		if (point.first == fR - 1 && point.second == fC - 1)
			return cnt;

		for(int i = 0; i < 4; i++)
		{
			int dy = point.first + movement[i].first;
			int dx = point.second + movement[i].second;

			if (dy < 0 || dy >= H || dx < 0 || dx >= W) continue;

			if (v[dy][dx]) continue;

			if(CanMove({dy,dx}, i))
			{
				q.push({{ dy,dx }, cnt + 1});
				v[dy][dx] = true;
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H;
	cin >> W;

	for(int y = 0; y < H; y++)
	{
		for(int x = 0; x < W; x++)
		{
			int temp = 0;
			cin >> temp;
			board[y][x] = temp;
		}
	}

	cin >> sH; cin >> sW;

	int sR = 0;
	int sC = 0;

	cin >> sR; cin >> sC; cin >> fR; cin >> fC;

	cout<<BFS({sR-1, sC-1});
}