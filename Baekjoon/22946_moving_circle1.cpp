#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int N;

struct Circle
{
	//x, y
	pair<int, int> center;
	int r;
	int idx;
};

vector<int> g[5002];
vector<Circle> circles;
bool v[5002];

bool InsideCheck(Circle c1, Circle c2)
{
	int d = sqrt(pow(c1.center.first - c2.center.first, 2) + pow(c1.center.second - c2.center.second, 2));
	if (d == 0 || d < abs(c1.r - c2.r))
		return true;

	return false;
}

int DFS(int curr, int depth)
{
	v[curr] = true;

	int cnt = depth;
	for (int i = 0; i < g[curr].size(); i++)
	{
		int next = g[curr][i];
		if(!v[next])
		{
			depth = max(depth, DFS(next, cnt + 1));
		}
	}
	v[curr] = false;

	return depth;
}

bool cmp(Circle c1, Circle c2)
{
	return c1.r > c2.r;
}

void ConnectGraph(int curr)
{
	v[curr] = true;

	for (int i = curr + 1; i <= N; i++)
	{
		if(!v[i] && InsideCheck(circles[curr], circles[i]))
		{
			g[circles[curr].idx].push_back(circles[i].idx);
			g[circles[i].idx].push_back(circles[curr].idx);
			v[i] = true;
			ConnectGraph(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	circles.push_back({ {0,0}, 10000000, 0 });
	for (int i = 1; i <= N; i++)
	{
		int x, y, r = 0;
		cin >> x; cin >> y; cin >> r;
		circles.push_back({ {x,y}, r, i });
	}

    sort(circles.begin(), circles.end(), cmp);

	ConnectGraph(0);

	for (int i = 0; i <= N; i++)
		v[i] = false;

	int ans = -1;
	for(int i = 0; i <= N; i++)
	{
		ans = max(DFS(i, 0), ans);
	}

	cout << ans;
}