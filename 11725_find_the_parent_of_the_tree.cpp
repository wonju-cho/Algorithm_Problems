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