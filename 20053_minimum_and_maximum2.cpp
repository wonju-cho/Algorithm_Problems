#include<iostream>
#include<queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0; cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N = 0; cin >> N;
		priority_queue<int> pq1;
		priority_queue<int, vector<int>, greater<int>> pq2;

		for (int n = 0; n < N; n++)
		{
			int num = 0; cin >> num;
			pq1.push(num);
			pq2.push(num);
		}
		cout << pq2.top() << " ";
		cout << pq1.top() << "\n";
	}
}