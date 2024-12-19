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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

	for(int i = 0; i < N; i++)
    {
        int num = 0; cin >> num;
        int zero[MAX]; int one[MAX];
        zero[0] = 1; zero[1] = 0;
        one[0] = 0; one[1] = 1;

        for(int j = 2; j <= num; j++)
        {
            zero[j] = zero[j - 1] + zero[j - 2];
            one[j] = one[j - 1] + one[j - 2];
        }

        cout << zero[num] << " " << one[num] << "\n";
    }

    return 0;
}