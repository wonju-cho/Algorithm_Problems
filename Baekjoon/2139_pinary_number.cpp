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

#define MAX 91
long long dp[MAX][2];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	//1. 이친수는 0으로 시작하지 않는다.
    //2. 이친수에서는 1이 두 번 연속으로 나타나지 않는다. 즉 11을 부분 문자열로 갖지 않는다.
    //1, 10, 100, 101, 1000, 1001 -> O | 0010101, 101101 -> X
    //1 <= N <= 90, N자리 이친수의 개수 
    int N; cin >> N;
    dp[1][0] = 0; dp[1][1] = 1;
    for(int i = 2; i <= N; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[N][0] + dp[N][1];

    return 0;
}