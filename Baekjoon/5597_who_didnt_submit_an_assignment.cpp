#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//hash, pq
	unordered_map<int, bool> list;
	for(int i = 0; i < 30; i++)
	{
		int num = 0; cin >> num;
		list[num] = true;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 1; i <= 30; i++)
	{
		if (!list[i])
			pq.push(i);
	}

	cout << pq.top()<<"\n";
	pq.pop();
	cout << pq.top();

	//arr
	int arr[31] = {};

	for(int i = 0; i < 30; i++)
	{
		int num = 0; cin >> num;
		arr[num] = 1;
	}

	for(int i = 1; i <= 30; i++)
	{
		if (arr[i] != 1)
			cout << i << "\n";
	}
}