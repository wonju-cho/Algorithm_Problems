#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 21
int N;
int population[MAX][MAX];
int district[MAX][MAX];
int res = 999999999;
pair<int, int> movement[8] = { {-1,0}, {1,0}, {0,-1}, {0,1}, {-1, -1}, {-1, 1}, {1,-1}, {1, 1} };

int FillInner(pair<int,int> s, int (&arr)[MAX][MAX])
{
	bool v[MAX][MAX] = {};
	int cnt = population[s.first][s.second];

	queue<pair<int, int>> q;
	q.push(s);
	v[s.first][s.second] = true;
	arr[s.first][s.second] = 5;

	while(!q.empty())
	{
		auto curr = q.front();
		q.pop();

		for(int m = 0; m < 8; m++)
		{
			int dy = curr.first + movement[m].first;
			int dx = curr.second + movement[m].second;

			if (v[dy][dx]) continue;

			if (dy < 1 || dy > N || dx < 1 || dx > N) continue;

			if (arr[dy][dx] != 0) continue;

			arr[dy][dx] = 5;
			cnt += population[dy][dx];
			v[dy][dx] = true;
			q.push({ dy,dx });
		}
	}

	return cnt;
}

void GenerateDistrict(pair<int, int> p, int d1, int d2)
{
	if (p.first < 0 || p.second < 0) return;

	int maximum = -1;
	int minimum = 999999999;
	int arr[5] = {};

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			district[y][x] = 0;
		}
	}

	//5번 선거구
	pair<int, int> temp = p;

	//5-1
	for(int i = 0; i <= d1; i++, temp.first++, temp.second--)
	{
		district[temp.first][temp.second] = 5;
		arr[4] += population[temp.first][temp.second];
	}

	//5-2
	temp = p;
	for (int i = 0; i <= d2; i++, temp.first++, temp.second++)
	{
		if (district[temp.first][temp.second] == 5) continue;

		district[temp.first][temp.second] = 5;
		arr[4] += population[temp.first][temp.second];
	}

	//5-3
	temp = p; temp.first += d1; temp.second -= d1;
	for (int i = 0, j =0; i <= d2; i++, temp.first++, temp.second++, j++)
	{
		if (district[temp.first][temp.second] == 5) continue;

		district[temp.first][temp.second] = 5;
		arr[4] += population[temp.first][temp.second];
	}

	//5-4
	temp = p; temp.first += d2; temp.second += d2;
	for (int i = 0; i <= d1; i++, temp.first++, temp.second--)
	{
		if (district[temp.first][temp.second] == 5) continue;

		district[temp.first][temp.second] = 5;
		arr[4] += population[temp.first][temp.second];
	}

	//1
	for(int y = 1; y < p.first + d1; y++)
	{
		for(int x = 1; x <= p.second; x++)
		{
			if (district[y][x] == 5)
				break;

			district[y][x] = 1;
			arr[0] += population[y][x];
		}
	}

	//2
	for (int y = 1; y <= p.first + d2; y++)
	{
		for (int x = N; x > p.second; x--)
		{
			if (district[y][x] == 5)
				break;

			district[y][x] = 2;
			arr[1] += population[y][x];
		}
	}

	//3
	for (int y = p.first + d1; y <= N; y++)
	{
		for (int x = 1; x < p.second - d1 + d2; x++)
		{
			if (district[y][x] == 5)
				break;

			district[y][x] = 3;
			arr[2] += population[y][x];
		}
	}

	//4
	for (int y = p.first + d2 + 1; y <= N; y++)
	{
		for (int x = N; x >= p.second - d1 + d2; x--)
		{
			if (district[y][x] == 5)
				break;

			district[y][x] = 4;
			arr[3] += population[y][x];
		}
	}

	pair<int, int> start = { p.first + 1, p.second };
	arr[4] += FillInner(start, district);

	for(int i = 0; i < 5; i++)
	{
		if(arr[i] < minimum)
		{
			minimum = arr[i];
		}

		if(arr[i] > maximum)
		{
			maximum = arr[i];
		}
	}

	const int result = maximum - minimum;
	res = min(result, res);
}

void DivideDistrict()
{
	//x,y
	for(int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			for(int d1 = 1; d1 <= x - 1; d1++)
			{
				if (x - d1 < 1) continue;

				for(int d2 = 1; d2 <= N - x; d2++)
				{
					if (x + d2 > N) continue;

					if (y + d1 + d2 > N) continue;

					GenerateDistrict({ y,x }, d1, d2);
				}
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for(int y = 1; y <= N; y++)
	{
		for(int x = 1; x <= N; x++)
		{
			cin >> population[y][x];
		}
	}

	DivideDistrict();

	cout << res;
}