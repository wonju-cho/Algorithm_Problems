#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>

using namespace std;

struct Node
{
	int left = -1;
	int right = -1;
	int depth = 0;
	int col = 0;
};

void SetTree(unordered_map<int, Node>& t, int idx, int depth, int& col)
{
	if (idx == -1)
		return ;

	SetTree(t, t[idx].left, depth + 1, col);
	t[idx].depth = depth + 1;
	t[idx].col = col++;
	SetTree(t, t[idx].right, depth + 1, col);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; cin >> N;
	unordered_map<int, Node> tree;
	int root = N * (N + 1) / 2;
	for(int i = 0; i < N; i++)
	{
		int a = 0; int l = 0; int r = 0; cin >> a; cin >> l; cin >> r;
		tree[a].left = l;
		tree[a].right = r;

		if (l != -1)
			root -= l;
		if (r != -1)
			root -= r;
	}

	int col = 1;
	SetTree(tree, root, 0, col);

	//level, id
	map<int, vector<int>> levelTree;
	for(int i = 1; i <= N; i++)
	{
		levelTree[tree[i].depth].push_back(i);
	}

	//level, width
	pair<int,int> res = {1, 1};
	for (auto lt : levelTree)
	{
		int minCol = 10001;
		int maxCol = -1;
		for(auto id : lt.second)
		{
			minCol = min(minCol, tree[id].col);
			maxCol = max(maxCol, tree[id].col);
		}

		int width = maxCol - minCol + 1;
		if (width > res.second)
			res = { lt.first, width };
	}

	cout << res.first << " " << res.second;
}