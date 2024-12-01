#include <iostream>
#include <vector>

using namespace std;

int arr[100002];

void DFS(vector<vector<int>>& vec, vector<bool>& visited, int curr)
{
	visited[curr] = true;

	for (int i = 0; i < vec[curr].size(); i++)
	{
		if (visited[vec[curr][i]]) continue;

		arr[vec[curr][i]] = curr;
		DFS(vec, visited, vec[curr][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size = 0;
	cin >> size;

	vector<vector<int>> vec(size + 1);

	for (int i = 0; i < size-1; i++)
	{
		int start = 0;
		int end = 0;
		cin >> start;
		cin >> end;

		vec[start].push_back(end);
		vec[end].push_back(start);
	}

	vector<bool> visited(size + 1);
	DFS(vec, visited, 1);

	for(int i = 2; i <= size; i++)
	{
		cout << arr[i] << "\n";
	}

}

//BFS
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void BFS(vector<vector<int>>& g, int r, vector<bool>& v, vector<int>& res)
{
	queue<int> q;
	q.push(r);
	v[r] = true;

	while(!q.empty())
	{
		auto id = q.front();
		q.pop();

		for(int i = 0; i < g[id].size(); i++)
		{
			if(!v[g[id][i]])
			{
				q.push(g[id][i]);
				v[g[id][i]] = true;
				res[g[id][i]] = id;
			}
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

	vector<vector<int>> g(N + 1);
	vector<int> res(N + 1);
	vector<bool> v(N + 1);

	for(int i = 1; i < N; i++)
	{
		int s = 0;
		int e = 0;
		cin >> s;
		cin >> e;

		g[s].push_back(e);
		g[e].push_back(s);
	}

	BFS(g, 1, v, res);

	for (int i = 2; i <= N; i++)
		cout << res[i]<<"\n";
}