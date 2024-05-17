#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T = 0; cin >> T; int b[15][15] = {};
	for (int t = 1; t <= T; t++)
	{
		int N = 0; int M = 0; cin >> N >> M;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				cin >> b[y][x];
			}
		}

		pair<int, int> s = { 0,0 }; int limit = N - M; int max = 0;
		while (s.first <= limit && s.second <= limit)
		{
			int val = 0; auto initialVal = s;
			for (int y = 0; y < M; y++, s.first++)
			{
				for (int x = 0; x < M; x++, s.second++)
				{
					val += b[s.first][s.second];
				}
				s.second = initialVal.second;
			}
			
			if (val > max) max = val;
			
			s.second += 1;
			if (s.second <= limit)
				s.first = initialVal.first;
			else
			{
				initialVal.first++;
				s.second = 0;
				s.first = initialVal.first;
			}
		}
		cout << '#' << t << ' ' << max << "\n";
	}
}