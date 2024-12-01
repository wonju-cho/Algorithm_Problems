#include<iostream>
#include <queue>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int t = 1; t <= 10; t++)
	{
		int dump = 0; cin >> dump;
		priority_queue<int> pq1;
		priority_queue<int, vector<int>, greater<int>> pq2;
		for (int i = 0; i < 100; i++) 
		{
			int num = 0; cin >> num;
			pq1.push(num);
			pq2.push(num);
		}

		for (int i = 0; i < dump; i++)
		{
			int maximum = pq1.top(); //제일 큰 값
			int minimum = pq2.top(); //제일 작은 값
			pq1.pop(); pq2.pop();
			pq1.push(maximum - 1);
			pq2.push(minimum + 1);
		}
		int res = pq1.top() - pq2.top();
		cout << '#' << t << ' ' << res << "\n";
	}
    
    return 0;
}