#include <iostream>
#include <vector>

using namespace std;
#define MAX 367

struct Date
{
	bool hasPlan = false;
	int cnt = 0;
};

Date schedule[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> vec;
	int N = 0; cin >> N; int endDate = 0;

	for(int i = 0; i < N; i++)
	{
		int s = 0; int e = 0; cin >> s >> e;
		if (e > endDate) endDate = e;

		for (int i = s; i <= e; i++)
		{
			if (!schedule[i].hasPlan) schedule[i].hasPlan = true;
			schedule[i].cnt++;
		}
	}

	int width = 367; int height = 1; int res = 0;
	for(int i = 1; i <= endDate; i++)
	{
		auto s = schedule[i];
		if(!s.hasPlan && width != 367)
		{
			res += (i - width) * height;
			height = 1;
			width = 367;
		}

		if (height < s.cnt) height = s.cnt;
		if(s.hasPlan)
		{
			if(width > i)
			width = i;
		}
	}

	if(schedule[endDate].cnt > 0)
	{
		res += (endDate - width + 1) * height;
	}

	cout << res;
}