#include<iostream>

using namespace std;
#define MAX 49
int b[MAX][MAX];

pair<int, int> movement[2] = { {1,1}, {-1,-1} };

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T = 0; cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N = 0; cin >> N;
		for (int i = 0; i < N; i++)
		{
			string str = ""; getline(cin, str);
			if (str.empty()) getline(cin, str);
			for (int j = 0; j < str.length(); j++) 
			{
				b[i][j] = str[j] - '0';
			}
		}

		int res = 0; pair<int, int> s = { N / 2, 0 }; int move[2] = { (N / 2) + 1, N / 2 };  int idx = 0;
		for (int cnt = 0; cnt < N; cnt++)
		{
			for (int i = 0; i < move[idx]; i++) {
				res += b[s.first][s.second];
				s.first += movement[idx].first;
				s.second += movement[idx].second;
			}
			s.first -= movement[idx].first;
			s.second -= movement[idx].second;
			s.first -= 1;
			idx = (idx + 1) % 2;
		}
		cout << '#' << t << " " << res << '\n';
	}
    
    return 0;
}