//https://bba-dda.tistory.com/73
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0; cin >> T;

	for(int t = 0; t < T; t++)
	{
		int N = 0; cin >> N;
		vector<int> tree(N + 1);

		for(int i = 0; i < N-1; i++)
		{
			int A = 0; int B = 0; cin >> A; cin >> B;
			tree[B] = A;
		}
		int targetA = 0; int targetB = 0; cin >> targetA; cin >> targetB;
		vector<int> trackA; vector<int> trackB;

		int curr = targetA;
		while(curr != 0)
		{
			trackA.push_back(curr);
			curr = tree[curr];
		}

		curr = targetB;
		while (curr != 0)
		{
			trackB.push_back(curr);
			curr = tree[curr];
		}

		bool find = false;
		for(int a = 0; a < trackA.size(); a++)
		{
			if (find) break;
			for(int b = 0; b < trackB.size(); b++)
			{
				if(trackA[a] == trackB[b])
				{
					cout << trackA[a] << "\n";
					find = true;
					break;
				}
			}
		}
	}
}