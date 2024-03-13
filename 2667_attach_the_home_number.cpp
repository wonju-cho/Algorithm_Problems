#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

pair<int, int> movement[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int arr[25][25];
bool check[25][25];
int size;

int BFS(pair<int, int> p, int size)
{
	queue <pair<int, int>> q;
	q.push(p);
	check[p.first][p.second] = true;

	int cnt = 1;
	while (!q.empty())
	{
		auto point = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int dy = point.first + movement[i].first;
			int dx = point.second + movement[i].second;

			if (dx < 0 || dx > size - 1 || dy < 0 || dy > size - 1) continue;

			if (arr[dy][dx] == 1 && !check[dy][dx])
			{
				check[dy][dx] = true;
				cnt++;
				q.push({dy,dx});
			}
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size = 0;
	cin >> size;
	vector<int> res;

	for(int y = 0; y < size; y++)
	{
		string str = "";
		cin >> str;
		for(int x = 0; x < size; x++)
		{
			if (str[x] == '1')
				arr[y][x] = 1;
		}
	}

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if(arr[y][x] == 1 && !check[y][x])
			{
				res.push_back(BFS({ y, x }, size));
			}
		}
	}

	sort(res.begin(), res.end());

	cout << res.size() << "\n";
	for (auto r : res)
	{
		cout << r << "\n";
	}
}