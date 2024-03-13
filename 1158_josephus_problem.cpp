#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	int k  = 0;

	cin >> n;
	cin >> k;

	cout<<"<";
	queue<int> q;
	for(int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	while(!q.empty())
	{
		for(int i = 0; i < k-1; i++)
		{
			int num = q.front();
			q.pop();
			q.push(num);
		}

		if(q.size() == 1)
		{
			cout<<q.front();
		}
		else
			cout<<q.front()<<" ";;
		
		q.pop();
	}

	cout<<">"
}