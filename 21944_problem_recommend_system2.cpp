#include<iterator>
#include<iostream>
#include<map>
#include<set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	map<int, multiset<pair<int, int>>> algoMap;
	map<int, pair<int, int>> map;
	multiset<pair<int, int>> level;

	for(int i = 0; i < N; i++)
	{
		int p = 0;
		int l = 0;
		int g = 0;

		cin >> p;
		cin >> l;
		cin >> g;

		level.insert({ l, p });
		algoMap[g].insert({l,p});
		map[p] = {l , g};
	}

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		string command = "";
		int num = 0;

		cin >> command;
		cin >> num;

		if(command == "add")
		{
			int l = 0;
			int g = 0;
			cin >> l;
			cin >> g;

			level.insert({ l, num });
			algoMap[g].insert({ l,num });
			map[num] = { l,g };
		}
		else if(command == "recommend")
		{
			int x = 0;
			cin >> x;

			if(x == 1)
			{
				cout << prev(algoMap[num].end())->second << "\n";
			}
			else
			{
				cout << algoMap[num].begin()->second << "\n";
			}
		}
		else if(command == "recommend2")
		{
			if (num == 1)
			{
				cout << prev(level.end())->second << "\n";
			}
			else
			{
				cout << level.begin()->second << "\n";
			}

		}
		else if(command == "recommend3")
		{
			int l = 0;
			cin >> l;

			if(num == 1)
			{
				auto iter = level.lower_bound({ l, -1e9 });
				if (iter != level.end()) cout << iter->second << "\n";
				else cout << "-1\n";
			}
			else
			{
				auto iter = level.upper_bound({ l, -1e9 });
				if (iter != level.begin()) cout << (--iter)->second << "\n";
				else cout << "-1\n";
			}

		}
		else if (command == "solved")
		{
			int l = map[num].first;
			int g = map[num].second;

			algoMap[g].erase({ l, num });
			level.erase({ l, num });
			map.erase(num);
		}
	}

}