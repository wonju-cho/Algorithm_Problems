#include<iostream>
#include<vector>
#include <queue>

using namespace std;
int parent[1000001];
vector<int> tree[1000001];

void Clear(vector<int>& idx)
{
	for(int i = 0; i < idx.size(); i++)
	{
		parent[idx[i]] = 0;
		tree[idx[i]].clear();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0; int k = 0;
	while (cin >> n >> k)
	{
		if (n == 0 && k == 0) break;

		priority_queue<int, vector<int>, greater<int>> pq;
		vector<int> idx;
		int track = 0;
		for (int i = 0; i < n; i++)
		{
			int temp = 0; cin >> temp;
			if(i == 1)
			{
				tree[pq.top()].push_back(temp);
				parent[temp] = pq.top();
			}
			else if(i > 1)
			{
				if (temp - track != 1)
				{
					pq.pop();
				}
				parent[temp] = pq.top();
				tree[pq.top()].push_back(temp);
			}

			track = temp;
			pq.push(temp);
			idx.push_back(temp);
		}

		int gp = parent[parent[k]];
		int res = 0;
		for(int i = 0; i < tree[gp].size(); i++)
		{
			if (tree[gp][i] != parent[k])
				res += tree[tree[gp][i]].size();
		}
		cout << res << "\n";

		Clear(idx);
	}
}