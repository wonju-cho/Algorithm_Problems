#include<iostream>

using namespace std;

int preOrder[1001];
int inOrder[1001];

void PostOrder(int r, int s, int e)
{
	for(int i = s; i < e; i++)
	{
		if(preOrder[r] == inOrder[i])
		{
			PostOrder(r + 1, s, i);
			PostOrder(r + i + 1 - s, i + 1, e);
			cout << preOrder[r] << " ";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0; cin >> T;
	while(T > 0)
	{
		int N = 0; cin >> N;

		for(int i = 0; i < 2; i++)
		{
			for (int n = 0; n < N; n++)
			{
				int temp = 0; cin >> temp;
				if (i == 0)
					preOrder[n] = temp;
				else
					inOrder[n] = temp;
			}
		}

		PostOrder(0, 0, N);
		cout << "\n";
		T -= 1;
	}

}