#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int v;

void BFS(vector<vector<int>>& vec, vector<bool>& visited)
{
	queue<int> q;

	visited[v] = true;
	q.push(v);

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		for(int i = 0; i < vec[curr].size(); i++)
		{
			if (visited[vec[curr][i]]) continue;

			q.push(vec[curr][i]);
			visited[vec[curr][i]] = true;
			cout << vec[curr][i] << " ";
		}
	}
	cout << "\n";
}

void DFS(vector<vector<int>>& vec, int curr, vector<bool>& visited)
{
	visited[curr] = true;
	cout << curr << " ";

	for(int i = 0; i < vec[curr].size(); i++)
	{
		if (visited[vec[curr][i]]) continue;
		DFS(vec, vec[curr][i], visited);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size = 0;
	cin >> size;

	int edge = 0;
	cin >> edge;

	int start = 0;
	cin >> start;

	v = start;

	vector<vector<int>> network(size + 1);
	vector<bool> visited(size + 1, false);
	vector<bool> visited2(size + 1, false);

	for(int i = 0; i < edge; i++)
	{
		int start = 0;
		int end = 0;
		cin >> start;
		cin >> end;
		network[start].push_back(end);
		network[end].push_back(start);
	}

	for(int i = 1; i < size + 1; i++)
	{
		sort(network[i].begin(), network[i].end());
	}

	DFS(network, v, visited2);
	cout << "\n";
	BFS(network, visited);

}