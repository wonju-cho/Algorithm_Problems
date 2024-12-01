#include <iostream>

using namespace std;

bool bulbs[4001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0; cin >> N; cin >> M;

	for(int n = 1; n <= N; n++)
	{
		int num = 0; cin >> num;
		bulbs[n] = num;
	}

	for(int m = 0; m < M; m++)
	{
		int a = 0; cin >> a;
		if(a == 1)
		{
			int i = 0; int x = 0; cin >> i; cin >> x;
			bulbs[i] = x;
		}
		else if(a == 2)
		{
			int l = 0; int r = 0; cin >> l; cin >> r;
			for(int s = l; s <= r; s++)
			{
				bulbs[s] = !bulbs[s];
			}
		}
		else if(a == 3)
		{
			int l = 0; int r = 0; cin >> l; cin >> r;
			for (int s = l; s <= r; s++)
			{
				bulbs[s] = false;
			}
		}
		else
		{
			int l = 0; int r = 0; cin >> l; cin >> r;
			for (int s = l; s <= r; s++)
			{
				bulbs[s] = true;
			}
		}
	}

	for (int n = 1; n <= N; n++)
	{
		cout << bulbs[n]<<" ";
	}
}
