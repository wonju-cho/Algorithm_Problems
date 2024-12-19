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

#define MAX 1000001

int dp[MAX];

int main() {
    int N; cin >> N;

    dp[1] = 0;
    for(int i = 2; i <= N; i++)
    {
        int num = N;
	    if(i%2 == 0)
	    {
            num = min(dp[i / 2] + 1, num);
	    }
        if(i % 3 == 0)
        {
            num = min(dp[i / 3] + 1, num);
        }
        num = min(dp[i - 1] + 1, num);

        dp[i] = num;
    }

    cout << dp[N]<<"\n";

    cout << N << " ";
    while (N != 1)
    {
        //first: 값 second: 비교할 dp값
        pair<int, int> temp;
    	temp.first = N; temp.second = N;
        if (N % 2 == 0)
        {
            if (temp.second > dp[N / 2])
            {
                temp.first = N / 2;
                temp.second = dp[N / 2];
            }
        }
        if (N % 3 == 0)
        {
            if(temp.second > dp[N/3])
            {
                temp.first = N / 3;
                temp.second = dp[N / 3];
            }
        }
        if(temp.second > dp[N-1])
        {
            temp.first = N - 1;
            temp.second = dp[N - 1];
        }
        N = temp.first;
        cout << temp.first<<" ";
    }

    return 0;
}