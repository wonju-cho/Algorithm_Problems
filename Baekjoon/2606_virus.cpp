#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int BFS(vector<vector<int>>& vec)
{
	queue<int> q;
	vector<bool> visited(vec.size());
	int res = 0;

	visited[1] = true;
	q.push(1);

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		for(int i = 0; i < vec[curr].size(); i++)
		{
			if (visited[vec[curr][i]]) continue;

			q.push(vec[curr][i]);
			visited[vec[curr][i]] = true;
			res++;
		}

	}

	return res;
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

	int res = 0;
	vector<vector<int>> network(size + 1);

	for(int i = 0; i < edge; i++)
	{
		int start = 0;
		int end = 0;
		cin >> start;
		cin >> end;
		network[start].push_back(end);
		network[end].push_back(start);
	}

	res = BFS(network);

	cout << res;
}