#include<iostream>

using namespace std;
#define MAX 11
int b[MAX][MAX];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T = 0; cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cout << '#' << t << '\n';
		int N = 0; cin >> N;
		if (N == 1)
		{
			cout << 1 << "\n";
			continue;
		}

		b[1][0] = 1;
		for (int i = 2; i <= N; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (j == 0 || j == i - 1)
				{
					b[i][j] = 1;
				}
				else {
					b[i][j] = b[i - 1][j - 1] + b[i - 1][j];
				}
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < i; j++)
			{
				cout << b[i][j] << ' ';
			}
			cout << "\n";
		}
	}
}