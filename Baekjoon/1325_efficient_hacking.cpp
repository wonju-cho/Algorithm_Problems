#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int arr[10001];

void BFS(vector<vector<int>>& vec, int start)
{
	vector<bool> visited(vec.size(), false);

	queue<int> q;
	q.push(start);
    visited[start] = true;

	int cnt = 0;

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		cnt++;

		for(int i = 0; i < vec[curr].size(); i++)
		{
			if (visited[vec[curr][i]]) continue;

			q.push(vec[curr][i]);
			visited[vec[curr][i]] = true;
		}
	}

	arr[start] = cnt;
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

	vector<vector<int>> computers(size + 1);

	for (int i = 0; i < edge; i++)
	{
		int start = 0;
		int end = 0;
		cin >> start;
		cin >> end;

		computers[end].push_back(start);
	}

	int max = -1;
	for(int i = 1; i <= size; i++)
	{
		BFS(computers, i);
		if (max < arr[i]) max = arr[i];
	}

	for (int i = 1; i <= size; i++)
	{
		if (arr[i] == max)
			cout << i << " ";
	}
}