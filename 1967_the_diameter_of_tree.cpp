#include<vector>
#include<iostream>

using namespace std;

struct Node
{
	int idx;
	int cost;
};

int N;
vector<Node> graph[100001];
bool v[100001];
int maxCost = 0;
int maxNode = 0;

void DFS(int idx, int cost)
{
	if (v[idx]) return;

	v[idx] = true;
	if (maxCost < cost)
	{
		maxCost = cost;
		maxNode = idx;
	}

	for(int i = 0; i < graph[idx].size(); i++)
	{
		int nextCost = graph[idx][i].cost;
		int nextIdx = graph[idx][i].idx;

		DFS(nextIdx, nextCost + cost);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a = 0;
		int b = 0;
		int c = 0;
		cin >> a; cin >> b; cin >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	DFS(1, 0);

	maxCost = 0;

	for (int i = 0; i <= N; i++)
		v[i] = false;

	DFS(maxNode, 0);

	cout << maxCost;
}