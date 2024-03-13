#include<queue>
#include<iostream>
#include <unordered_set>

using namespace std;

int N;
int K;
long long res;
queue<int> q;
unordered_set<int> uns;

int movement[2] = { 1,-1 };

void BFS()
{
	int dis = 0;
	while (!q.empty())
	{
		int size = q.size();
		dis++;

		for(int i = 0; i < size; i++)
		{
			auto curr = q.front();
			q.pop();

			for(int j = 0; j < 2; j++)
			{
				int next = curr + movement[j];
				if(uns.count(next) == 0)
				{
					q.push(next);
					uns.insert(next);
					res += dis;
					if (--K == 0)
						return;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> K;

	for(int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		uns.insert(temp);
		q.push(temp);
	}

	BFS();
	cout << res;
}