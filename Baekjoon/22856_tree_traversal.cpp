#include <vector>
#include <iostream>

using namespace std;
struct Node
{
	int l = -1;
	int r = -1;
};

int N;
Node g[100000];
bool flag = false;
int res;
int e;

void InOrder(int node, vector<int>& vec)
{
	if (node == -1) {
		return;
	}

	InOrder(g[node].l, vec);
	vec.push_back(node);
	InOrder(g[node].r, vec);
}

void SimilarInOrder(int node)
{
	if (node == -1) {
		return ;
	}

	if (g[node].l != -1) res++;
	SimilarInOrder(g[node].l);
	if (g[node].l != -1 && !flag) res++;

	if (node == e) flag = true;

	if (g[node].r != -1) res++;
	SimilarInOrder(g[node].r);
	if (g[node].r != -1 && !flag) res++;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for(int i = 1; i <= N; i++)
	{
		int node = 0; int l = 0; int r = 0; cin >> node >> l >> r;
		g[node].l = l;
		g[node].r = r;
	}

	if(N == 1)
	{
		cout << 0;
		return 0;
	}

	vector<int> vec;
	InOrder(1, vec);
	e = vec.back();
	SimilarInOrder(1);
	cout << res;
}