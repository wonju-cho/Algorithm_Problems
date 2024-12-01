#include <iostream>

using namespace std;
int N;
bool isUsed1[40]; //y: col
bool isUsed2[40]; //x + y: anti diagonal, left
bool isUsed3[40]; //y - x + n - 1: main diagonal, right
int res;

void NQueen(int curr)
{

	if(curr == N)
	{
		res++;
		return;
	}

	for(int x = 0; x < N; x++)
	{
		if (!isUsed1[x] && !isUsed2[x + curr] && !isUsed3[curr - x + N - 1])
		{
			isUsed1[x] = true;
			isUsed2[x + curr] = true;
			isUsed3[curr - x + N - 1] = true;

			NQueen(curr + 1);

			isUsed1[x] = false;
			isUsed2[x + curr] = false;
			isUsed3[curr - x + N - 1] = false;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	NQueen(0);

	cout << res;
}