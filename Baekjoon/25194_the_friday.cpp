#include <iostream>
#include <vector>

using namespace std;
int schedule[1001];
bool dp[7];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> schedule[i];
	}

	dp[0] = true;
	for(int i = 0; i < N; i++)
	{
		vector<int> vec;
		int task = schedule[i];
		for(int d = 0; d < 7; d++)
		{
			if(dp[d])
			{
				vec.push_back((d + task) % 7);
			}
		}

		for (auto v : vec)
		{
			dp[v] = true;
		}
	}

	if (dp[4])
		cout << "YES";
	else cout << "NO";
}