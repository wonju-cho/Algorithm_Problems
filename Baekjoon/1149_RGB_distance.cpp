#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX 1000

int main() {

	// 1번 집의 색은 2번 집의 색과 같지 않아야 함
	// N번 집의 색은 N-1번 집의 색과 같지 않아야 함
	// i(2<=i<=N-1)번 집의 색은 i-1, i+1번 집의 색과 같지 않아야 한다
	int N = 0; cin >> N;
	//row: 집의 번호, column: 색깔(R, G, B)
	int dp[MAX][3] = {};
	int arr[MAX][3] = {};
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
			if (i == 0)
				dp[i][j] = arr[i][j];
		}
	}

	int res = INT_MAX;
	for (int houseNum = 1; houseNum <= N; houseNum++)
	{
		for (int color = 0; color < 3; color++)
		{
			int minCost = 1001;
			if (color == 0)
				minCost = min(dp[houseNum - 1][1], dp[houseNum - 1][2]);
			else if (color == 1)
				minCost = min(dp[houseNum - 1][0], dp[houseNum - 1][2]);
			else minCost = min(dp[houseNum - 1][0], dp[houseNum - 1][1]);

			dp[houseNum][color] = arr[houseNum][color] + minCost;
			if (houseNum == N - 1) res = min(res, dp[houseNum][color]);
		}
	}

	cout << res;
}