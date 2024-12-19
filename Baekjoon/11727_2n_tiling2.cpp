#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <climits> //정수 형식에 대한 정보: INT_MIN, INT_MAX
#include <algorithm>
#include <fstream>
#include <functional>
#include <memory>

using namespace std;

#define MAX 1001
int dp[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
	
    dp[1] = 1; dp[2] = 3;
    for(int i = 3; i <= N; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }

    cout << dp[N];

    return 0;
}