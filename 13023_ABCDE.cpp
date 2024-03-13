#include<iostream>
#include<vector>

using namespace std;
int N;
int M;

bool res;

void DFS(int depth, int curr, vector<vector<int>>& g, vector<bool>& v){
	if(depth == 4)
	{
		res = true;
		return;
	}

	for(int i = 0; i < g[curr].size(); i++)
	{
		if (v[g[curr][i]]) continue;

		v[g[curr][i]] = true;
		DFS(depth + 1, g[curr][i], g, v);
        v[g[curr][i]] = false;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;

	vector<vector<int>> graph(N);

	for(int i = 0; i < M; i++)
	{
		int a = 0;
		int b = 0;
		cin >> a; cin >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i = 0; i < N; i++)
	{
		vector<bool> visited(N);
        visited[i] = true;
		DFS(0, i, graph, visited);
		if (res == true)
			break;
	}

	cout << res;

}