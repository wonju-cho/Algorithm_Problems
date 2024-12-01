#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

bool v[200001];
int N;

struct Node
{
	int id;
	int d;
};

pair<int,int> GigaBFS(int s, vector<vector<Node>>& t)
{
	pair<int,int> res;
	//id, d
	queue<pair<int,int>> q;
	q.push({ s, 0 });
	v[s] = true;

	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();

		if(t[curr.first].size() > 2 || (curr.first == s && t[curr.first].size() >= 2))
		{
			res = curr;
			break;
		}

		for (int i = 0; i < t[curr.first].size(); i++)
		{
			if(!v[t[curr.first][i].id])
			{
				q.push({ t[curr.first][i].id, t[curr.first][i].d + curr.second });
				v[t[curr.first][i].id] = true;
				res.second += t[curr.first][i].d;
			}
		}

	}

	return res;
}

int MaximumBranch(int s, vector<vector<Node>>& t)
{
	int res = 0;
	//id, cost
	queue<pair<int, int>> q;
	q.push({ s, 0 });
	v[s] = true;

	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();

		res = max(res, curr.second);

		for (int i = 0; i < t[curr.first].size(); i++)
		{
			if (!v[t[curr.first][i].id])
			{
				q.push({ t[curr.first][i].id, t[curr.first][i].d + curr.second });
				v[t[curr.first][i].id] = true;
			}
		}
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int R = 0; cin >> R;

	vector<vector<Node>> tree(N+1);

	for(int i = 0; i < N-1; i++)
	{
		int a = 0; int b = 0; int d = 0; cin >> a; cin >> b; cin >> d;
		tree[a].push_back({ b, d });
		tree[b].push_back({ a, d });
	}

	auto giga = GigaBFS(R, tree);
	v[giga.first] = false;
	cout<<giga.second<<" "<< MaximumBranch(giga.first, tree);
}