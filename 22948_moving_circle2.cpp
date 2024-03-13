#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

struct Circle
{
	int k;
	int x;
};

vector<int> g[200002];
vector<Circle> circles;
bool v[200002];

void DFS(int curr, int end, vector<int>& path)
{
	if(curr == end)
	{
		cout << path.size()<<"\n";

		for (auto p : path)
			cout << p << " ";

		return;
	}

	v[curr] = true;

	for(int i = 0; i < g[curr].size(); i++)
	{
		int next = g[curr][i];
		if(!v[next])
		{
			path.push_back(next);
			DFS(next, end, path);
			path.pop_back();
		}
	}
	v[curr] = false;
}

bool cmp(Circle c1, Circle c2)
{
	return c1.x < c2.x;
}

void ConnectGraph(int curr)
{
	stack<int> stk;
	stk.push(0);

	for(auto c : circles)
	{
		if (c.k < 0)
			stk.pop();
		else
		{
			g[stk.top()].push_back(c.k);
			g[c.k].push_back(stk.top());
			stk.push(c.k);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num, x, r = 0;
		cin >> num; cin >> x; cin >> r;
		circles.push_back({ num, x - r });
		circles.push_back({ -num, x + r });
	}

	int A = 0;
	int B = 0;

	cin >> A; cin >> B;

	sort(circles.begin(), circles.end(), cmp);

	ConnectGraph(0);

	vector<int> res;
	res.push_back(A);

	DFS(A, B, res);

}
