#include<iostream>

using namespace std;

int edges[500001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; cin >> N;
	int W = 0; cin >> W;
    
	for (int i = 0; i < N - 1; i++)
	{
		int U = 0; int V = 0; cin >> U; cin >> V;
		edges[U]++;
		edges[V]++;
	}

	double result = 0.f;
	for(int i = 2; i <= N; i++)
	{
		if(edges[i] == 1)
		{
			result++;
		}
	}

	result = W / result;
	cout.precision(10);
	cout << result;
}