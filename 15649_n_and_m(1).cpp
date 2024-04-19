#include <iostream>

using namespace std;
int N;
int M;
bool isUsed[10];
int arr[10];

void Func(int n)
{
	if(n == M)
	{
		for(int i = 0; i < M; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for(int i = 1; i <= N; i++)
	{
		if(!isUsed[i])
		{
			isUsed[i] = true;
			arr[n] = i;
			Func(n + 1);
			isUsed[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N; cin >> M;

	Func(0);
}