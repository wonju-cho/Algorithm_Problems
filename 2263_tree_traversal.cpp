//https://non-stop.tistory.com/128
#include<iostream>

using namespace std;

int inOrder[100001];
int postOrder[100001];
int idx[100001];

void PreOrder(int inS, int inE, int posS, int posE)
{
	if (inS > inE || posS > posE)
		return;

	int root = postOrder[posE];
	int rootIdx = idx[root];
	int leftSize = rootIdx - inS;

	cout << root << " ";

	PreOrder(inS, rootIdx - 1, posS, posS + leftSize - 1);
	PreOrder(rootIdx + 1, inE, posS + leftSize, posE - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; cin >> N;
	for(int i = 0; i < 2; i++)
	{
		for(int n = 0; n < N; n++)
		{
			int temp = 0; cin >> temp;
			if (i == 0)
			{
				inOrder[n] = temp;
				idx[temp] = n;
			}
			else
				postOrder[n] = temp;
		}
	}

	PreOrder(0, N-1, 0, N-1);
}