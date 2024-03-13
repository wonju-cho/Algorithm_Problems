#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N; cin >> M;

	deque<int> dq;

	for(int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	int res = 0;
	while(M > 0)
	{
		int target = 0;
		cin >> target;
		auto idx = find(dq.begin(), dq.end(), target) - dq.begin(); //idx 위치 구하는 방법

		if (dq.size() - idx < idx)
		{
			while (dq.front() != target)
			{
				int temp = dq.back();
				dq.pop_back();
				dq.push_front(temp);
				res++;
			}
		}
		else
		{
			while (dq.front() != target)
			{
				int temp = dq.front();
				dq.pop_front();
				dq.push_back(temp);
				res++;
			}
		}
		M--;
		dq.pop_front();
	}

	cout << res;
}
