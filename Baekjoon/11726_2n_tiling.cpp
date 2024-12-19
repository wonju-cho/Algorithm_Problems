#include <iostream>

using namespace std;

#define MAX 1001

int main() {
	
	int N = 0; cin >> N;
	int dp[MAX] = {};
	dp[1] = 1; dp[2] = 2;
	for(int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[N];
}