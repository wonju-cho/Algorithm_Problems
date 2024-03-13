#include<iostream>
#include<set>

using namespace std;

int graph[100];
bool visited[100];
set<int> res;

void DFS(int start, int curr)
{
	if(visited[curr])
	{
		if(curr == start)
		{
			res.insert(graph[curr]);
		}
		return;
	}

	visited[curr] = true;
	DFS(start, graph[curr]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size = 0;
	cin >> size;

	for(int i = 1; i <= size; i++)
	{
		int temp = 0;
		cin >> temp;
		graph[i] = temp;
	}

	for(int i = 1; i <= size; i++)
	{
        fill(&visited[0], &visited[100], false);
		DFS(i, i);
	}

	cout << res.size() << "\n";
	for(auto r : res)
	{
		cout << r << "\n";
	}
}