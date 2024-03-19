#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

bool BFS(unordered_map<int,vector<int>>& e, int r, unordered_map<int, bool>& v)
{
	queue<int> q;
	q.push(r);
	v[r] = true;

	while(!q.empty())
	{
		auto id = q.front();
		q.pop();

		for (int i = 0; i < e[id].size(); i++)
		{
			if(v[e[id][i]])
			{
				return false;
			}

			if(!v[e[id][i]])
			{
				v[e[id][i]] = true;
				q.push(e[id][i]);
			}
		}
	}

	for(auto vc : v)
	{
		if (!vc.second)
			return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k = 0;

	while(true)
	{
		unordered_map<int, vector<int>> edges;
		unordered_map<int, bool> visited;
		set<int> s;
		int u = 0;
		int v = 0;
		int edgeCount = 0;
		int root = -1;
		k++;

		while(true)
		{
			cin >> u; cin >> v;
			if (u == 0 && v == 0)
				break;
			if (u == -1 && v == -1)
				return 0;

			edges[u].push_back(v);
			s.insert(v);
			
			if (!visited.count(u))
				visited[u] = false;
			if (!visited.count(v))
				visited[v] = false;

			edgeCount++;
		}

		if(edges.empty())
		{
			cout << "Case " << k << " is a tree.\n";
			continue;
		}

		int cnt = 0;
		for (auto e : edges)
		{
			if (s.count(e.first) != 1)
			{
				root = e.first;
				cnt++;
			}
		}

		bool isTree = BFS(edges, root, visited);

		if (root == -1 || cnt > 1 || !isTree || visited.size() != edgeCount + 1) //root가 존재하며 root는 하나여야만 함
		{
			cout << "Case " << k << " is not a tree.\n";
		}
		else
			cout << "Case " << k << " is a tree.\n";
	}
}