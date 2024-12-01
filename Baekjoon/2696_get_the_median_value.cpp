#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int total = 0;
	cin >> total;

	for(int i = 0 ; i < total; i++)
	{
		int n = 0;
		cin >> n;

		if(n % 2 == 1)
		{
			cout<< n / 2 + 1;
		}
		else
		{
			cout<< n / 2;
		}

		priority_queue<int> maxHeap;
		priority_queue<int, vector<int>, greater<int>> minHeap;

		for(int j = 0, check = 0; j < n; j++)
		{
			int temp = 0;
			cin >> temp;

			if(maxHeap.empty() || temp < maxHeap.top())
			{
				maxHeap.push(temp);
			}
			else
			{
				minHeap.push(temp);
			}

			if(maxHeap.size() > minHeap.size() + 1)
			{
				minHeap.push(maxHeap.top());
				maxHeap.pop();
			}
			else if(minHeap.size() > maxHeap.size())
			{
				maxHeap.push(minHeap.top());
				minHeap.pop();
			}

			if(j % 2 == 0)
			{
				if (check != 0 && check % 10 == 0)
					cout<<"\n";

				cout << maxHeap.top();
				check++;
			}
			
		}

		cout << "\n";
	}

}