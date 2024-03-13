#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, cnt;
vector<int> g[10001];
int pathV[10001];
bool v[10001];

struct Node
{
	int idx;
	int cost;
};

int BFS(int s, int e)
{
	queue<Node> q;
	v[s] = true;
	q.push({ s,0 });

	while(!q.empty())
	{
		auto curr = q.front();
		q.pop();

		for(int i = 0; i < g[curr.idx].size(); i++)
		{
			if(!v[g[curr.idx][i]])
			{
				q.push({ g[curr.idx][i], curr.cost + 1 });
				v[g[curr.idx][i]] = true;
				pathV[g[curr.idx][i]] = curr.idx;
			}

			if (g[curr.idx][i] == e)
			{
				return curr.cost + 1;
			}
		}
	}

	return -1;
}

void Initialize(int E)
{
	for(int i = 0; i <= N; i++)
	{
		v[i] = false;
	}

	int k = pathV[E];
	while(k != 0)
	{
		v[k] = true;
		k = pathV[k];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N; cin >> M;

	for(int i = 0; i < M; i++)
	{
		int a = 0;
		int b = 0;
		cin >> a; cin >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for(int i = 1; i <= N; i++)
	{
		sort(g[i].begin(), g[i].end());
	}

	int S = 0;
	int E = 0;
	cin >> S; cin >> E;

	int path1 = 0;
	int path2 = 0;

	path1 = BFS(S, E);

	Initialize(E);

	path2 = BFS(E, S);

	cout << path1 + path2;
}