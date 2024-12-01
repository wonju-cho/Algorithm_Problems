#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	vector<vector<int>> g(N + 1);

	for(int i = 0; i < N-1; i++)
	{
		int a = 0;
		int b = 0;
		cin >> a;
		cin >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int q = 0;
	cin >> q;

	for (int i = 0; i < q; i++)
	{
		int t = 0;
		int k = 0;
		cin >> t;
		cin >> k;

		if (t == 1)
		{
			if (g[k].size() == 1)
				cout << "no\n";
			else
				cout << "yes\n";
		}
		else
			cout << "yes\n";
	}
}