#include <iostream>
#include <string>

using namespace std;

bool CanDistribute(string& chicken, int maxDays, int totalX)
{
	int neededX = 0;
	int currentStreak = 0;

	for(auto day : chicken)
	{
		currentStreak++;
		if(currentStreak > maxDays)
		{
			neededX++;
			currentStreak = 1;
		}
	}

	if (neededX <= totalX)
		return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; cin >> N;
	string str; cin >> str;
	string chicken;

	for (int i = 0; i < N; i++)
	{
		if (str[i] == 'C') chicken += 'C';
	}

	int len = chicken.length();
	if (N - chicken.length() == 0)
	{
		cout << chicken.length();
		return 0;
	}

	int l = 1; int r = chicken.length(); int best = chicken.length(); int totalX = N - chicken.length();
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if (CanDistribute(chicken, mid, totalX))
		{
			best = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}

	cout << best;
}