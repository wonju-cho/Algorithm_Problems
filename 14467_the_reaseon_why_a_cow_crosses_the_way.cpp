#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; cin >> N;
	int res = 0;

	unordered_map<int, bool> cows;
	for (int n = 0; n < N; n++)
	{
		int id = 0; int dir = 0; cin >> id; cin >> dir;
		if (cows.count(id) == 0)
			cows[id] = dir;
		else
		{
			if (cows[id] != dir) res++;
			cows[id] = dir;
		}
	}

	cout << res;
}