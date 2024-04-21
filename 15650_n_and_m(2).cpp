//recursion
#include <iostream>

using namespace std;
bool v[9];
int N; int M;

void Recursion(int curr, int pre)
{
	if(curr == M)
	{
		for(int i = 1; i <= N; i++)
		{
			if(v[i])
			{
				cout << i<<' ';
			}
		}
		cout << "\n";

		return;
	}

	for(int i = 1; i <= N; i++)
	{
		if(!v[i] && pre <= i)
		{
			v[i] = true;
			Recursion(curr + 1, i);
			v[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	Recursion(0, 1);
}