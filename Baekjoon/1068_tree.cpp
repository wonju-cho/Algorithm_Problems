#include<iostream>
#include<queue>
#include<vector>

using namespace std;

bool v[51];

void BFS(int target, vector<vector<int>>& t)
{
	queue<int> q;
	q.push(target);
	v[target] = true;

	while(!q.empty())
	{
		auto curr = q.front();
		q.pop();

		for (int i = 0; i < t[curr].size(); i++)
		{
			if(!v[t[curr][i]])
			{
				q.push(t[curr][i]);
				v[t[curr][i]] = true;
			}
		}
		t[curr].clear();
		t[curr].push_back(-2);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	vector<vector<int>> tree(N);
	int root = -1;
	for(int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;

		if(temp == -1)
		{
			root = i;
		}
		else
			tree[temp].push_back(i);
	}

	int target = 0;
	cin >> target;

	if(target == root)
	{
		cout << 0;
		return 0;
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < tree[i].size(); j++)
		{
			if (tree[i][j] == target)
			{
				if(!v[tree[i][j]])
					BFS(target, tree);

				tree[i].erase(tree[i].begin() + j);
			}

		}
	}

	int result = 0;
	for(int i = 0; i < N; i++)
	{
		if (tree[i].empty())
			result++;
	}

	cout << result;
}