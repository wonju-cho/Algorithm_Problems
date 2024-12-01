#include<iostream>

using namespace std;

#define MAX 10
int b[MAX][MAX];
int N;
pair<int, int> movement[4] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0; cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;

		int dist = N; int size = N * N; pair<int, int> s = { 0,0 }; int num = 1; int idx = 0; bool flag = false;
		while (num <= size)
		{
			for (int i = 0; i < 2; i++)
			{
				for (int d = 0; d < dist; d++)
				{
					b[s.first][s.second] = num;
					num++;
					if (num > size) {
						flag = true;
						break;
					}
					s.first += movement[idx].first;
					s.second += movement[idx].second;
				}

				if (flag) break;
				
				if (i == 0) num -= 1;
				s.first -= movement[idx].first;
				s.second -= movement[idx].second;
				idx = (idx + 1) % 4;
			}

			s.first += movement[idx].first;
			s.second += movement[idx].second;
			dist -= 1;
		}

		cout << "#" << t << "\n";
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				cout << b[y][x]<<' ';
				b[y][x] = 0;
			}
			cout << "\n";
		}
	}
}