#include<iostream>

using namespace std;
#define MAX 15
int N; int K;
int b[MAX][MAX];
bool col[MAX][MAX];
bool row[MAX][MAX];

int IsAvailable(pair<int, int> p)
{
	int cnt = 0; int res = 0;
	//y check
	pair<int, int> temp = p;
	if (!col[temp.first][temp.second])
	{
		while (temp.first < N && b[temp.first][temp.second])
		{
			if (b[temp.first][temp.second] == 1)
			{
				cnt++;
			}
			temp.first++;
		}
	}

	if (cnt == K)
	{
		res++;
		temp.first--;
		while (temp.first >= p.first)
		{
			col[temp.first][temp.second] = true;
			temp.first--;
		}
	}
	else if (cnt > K)
	{
		temp.first--;
		while (temp.first >= p.first)
		{
			col[temp.first][temp.second] = true;
			temp.first--;
		}
	}
	cnt = 0;
	//x check
	temp = p;
	if (!row[temp.first][temp.second])
	{
		while (temp.second < N && b[temp.first][temp.second])
		{
			if (b[temp.first][temp.second] == 1)
			{
				cnt++;
			}
			temp.second++;
		}
	}

	if (cnt == K)
	{
		temp.second--;
		while (temp.second >= p.second)
		{
			row[temp.first][temp.second] = true;
			temp.second--;
		}

		res++;
	}
	else if(cnt > K)
	{
		temp.second--;
		while (temp.second >= p.second)
		{
			row[temp.first][temp.second] = true;
			temp.second--;
		}
	}

	return res;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T = 0; cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> K;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				cin >> b[y][x];
			}
		}

		int res = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (b[y][x] == 1)
				{
					int val = IsAvailable(pair<int, int>{ y, x });
					if (val > 0)
					{
						res += val;
					}
				}
			}
		}
		
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				col[y][x] = false;
				row[y][x] = false;
			}
		}
		cout << '#' << t << " " << res << '\n';
	}
    return 0;
}