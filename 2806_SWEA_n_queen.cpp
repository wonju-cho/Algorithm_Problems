#include<iostream>

using namespace std;

#define MAX 20
int N; int res;
bool colCheck[MAX];
bool antiDiagonal[MAX];
bool mainDiagonal[MAX];

void NQueen(int cnt) {
	if (cnt == N)
	{
		res++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (!colCheck[i] && !antiDiagonal[i + cnt] && !mainDiagonal[cnt - i + N - 1])
		{
			colCheck[i] = true;
			antiDiagonal[i + cnt] = true;
			mainDiagonal[cnt - i + N - 1] = true;
			NQueen(cnt + 1);
			colCheck[i] = false;
			antiDiagonal[i + cnt] = false;
			mainDiagonal[cnt - i + N - 1] = false;
		}
	}

}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T = 0; cin >> T;
	
	for (int t = 1; t <= T; t++)
	{
		cin >> N; res = 0;
        for(int i = 0; i < N; i++){
            colCheck[i] = false;
			antiDiagonal[i] = false;
			mainDiagonal[i] = false;
        }
		NQueen(0);

		cout << '#' << t << ' ' << res << "\n";
	}
}