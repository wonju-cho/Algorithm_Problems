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

#define MAX 500
int triangle[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			cin >> triangle[i][j];
		}
	}

	int res = triangle[0][0];

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				triangle[i][j] = triangle[i - 1][0] + triangle[i][j];
			else if(j==i)
			{
				triangle[i][j] = triangle[i - 1][j-1] + triangle[i][j];
			}
			else
			{
				triangle[i][j] = max(triangle[i - 1][j - 1], triangle[i - 1][j]) + triangle[i][j];
			}

			if (i == N - 1)
				res = max(res, triangle[i][j]);
		}
	}

	cout << res;

    return 0;
}