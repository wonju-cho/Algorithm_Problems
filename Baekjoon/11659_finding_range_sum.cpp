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

#define MAX 100001

int arr[MAX];
long sum[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;

    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    sum[1] = arr[1];
    for(int i = 2; i <= N; i++)
    {
        sum[i] = arr[i] + sum[i - 1];
    }

    for(int i = 0; i < M; i++)
    {
        int s, e; cin >> s >> e;
        cout << sum[e] - sum[s - 1]<<"\n";
    }

    return 0;
}