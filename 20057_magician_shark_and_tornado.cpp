#include <iostream>

using namespace std;
#define MAX 500
int N;
int b[MAX][MAX];
pair<int, int> s;
int res = 0;
int rate[9] = { 5,10,10,2,7,7,2,1,1 };
pair<int, int> wind[4] = { {0,-1}, {1,0}, {0,1}, {-1,0} };
pair<int, int> sand[4][10] = {
	//5, 10, 10, 2 , 7, 7, 2, 1, 1, a
	{{ 0,-2 }, {-1,-1}, {1,-1}, {-2,0}, {-1,0}, {1,0}, {2,0}, {-1,1}, {1, 1}, {0, -1} },
	{{ 2,0 }, {1, -1}, {1,1}, {0,-2}, {0,-1}, {0,1}, {0,2}, {-1,-1}, {-1,1}, {1,0}},
	{{ 0,2 }, {-1, 1}, {1,1}, {-2,0}, {-1,0}, {1,0}, {2,0}, {-1,-1}, {1,-1}, {0,1}},
	{{-2,0}, {-1,-1}, {-1,1}, {0,-2}, {0,-1}, {0,1}, {0,2}, {1,-1}, {1,1}, {-1,0}}
};

void Wind(int si, pair<int,int> p)
{
	int original = b[p.first][p.second];
	int curr = b[p.first][p.second];
	b[p.first][p.second] = 0;
	
	for(int i = 0; i < 9; i++)
	{
		pair<int, int> temp = p;
		temp.first  += sand[si][i].first;
		temp.second += sand[si][i].second;
		int remain = original * rate[i] / 100;

		if (temp.first < 0 || temp.first >= N || temp.second < 0 || temp.second >= N)
		{
			res += remain;
		}
		else
		{
			b[temp.first][temp.second] += remain;
		}
			curr -= remain;
	}

	pair<int, int> alpha = p;
	alpha.first += sand[si][9].first; alpha.second += sand[si][9].second;
	if (alpha.first < 0 || alpha.first >= N || alpha.second < 0 || alpha.second >= N)
	{
		res += curr;
	}
	else
	{
		b[alpha.first][alpha.second] += curr;
	}
}

void Simulation()
{
	int dist = 1; int idx = 0; bool flag = false;
	while(!flag)
	{
		for (int i = 0; i < 2; i++)
		{
			for(int d = 0; d < dist; d++)
			{
				s.first += wind[idx].first;
				s.second += wind[idx].second;

				if (b[s.first][s.second] > 0)
				{
					Wind(idx, s);
				}

				if (s == pair<int, int>{0, 0})
				{
					flag = true;
					break;
				}
			}

			if (flag) break;

			idx = (idx + 1) % 4;
		}
		dist++;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < N; x++)
		{
			cin >> b[y][x];
		}
	}

	s = { N / 2 , N / 2 };

	Simulation();

	cout << res;
}