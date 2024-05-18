#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T = 0; cin >> T;
	//dp
	for (int t = 1; t <= T; t++)
	{
		int N = 0; int limit = 0; cin >> N >> limit;
		vector<pair<int, int>> vec(N);
		for (int i = 0; i < N; i++)
		{
			int t = 0; int k = 0; cin >> t >> k;//점수, 칼로리 
			vec[i] = { t,k };
		}

		vector<int> dp(limit + 1, 0); //dp[j]: j kcal일때 얻을 수 있는 최대 점수
		for (int i = 0; i < N; i++) {
			int score = vec[i].first;
			int kcal = vec[i].second;

			for (int j = limit; j >= kcal; j--) {
				//dp[j]: 현재 재료를 사용하지 않을 때
				//dp[j-kcal]: 현재 재료를 사용했을 때 얻을수 있는 점수
				dp[j] = max(dp[j], dp[j - kcal] + score);
			}
		}
		cout << '#' << t << " " << dp[limit] << '\n';
	}

}

//dfs, backtracking, sort
using namespace std;
#define MAX 20
int N; int limit;
bool v[MAX];

void FindBestCombination(vector<pair<int, int>>& vec, int idx, pair<int,int> curr, int& maximum) 
{
	if (curr.second > limit) return;
	if (curr.first > maximum) maximum = curr.first;

	for (int i = idx; i < N; i++) {
		if (!v[i]) {
			v[i] = true;
			FindBestCombination(vec, i, { curr.first + vec[i].first, curr.second + vec[i].second }, maximum);
			v[i] = false;
		}
	}
}

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second > p2.second;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T = 0; cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> limit;
		vector<pair<int, int>> vec(N);
		for (int i = 0; i < N; i++)
		{
			int t = 0; int k = 0; cin >> t >> k;//점수, 칼로리 
			vec[i] = { t,k };
		}

		sort(vec.begin(), vec.end(), cmp);
		int max = 0;
		FindBestCombination(vec, 0, { 0,0 }, max);
		cout << '#' << t << " " << max << '\n';
	}
}