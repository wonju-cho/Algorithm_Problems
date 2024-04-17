#include <iostream>

using namespace std;
#define MAX 10001

int cards[MAX];
int res[MAX];
int dCards[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; int K; cin >> N; cin >> K;

	for(int i = 1; i <= N; i++)
	{
		int temp = 0; cin >> temp;
		cards[i] = temp;
	}

	for (int i = 1; i <= N; i++)
	{
		int temp = 0; cin >> temp;
		dCards[i] = temp;
	}

	for(int k = 0; k < K; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			int originalCard = cards[i];
			int destination = dCards[i];
			res[destination] = originalCard;
		}

		for (int i = 1; i <= N; i++)
		{
			cards[i] = res[i];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << res[i] << ' ';
	}

}