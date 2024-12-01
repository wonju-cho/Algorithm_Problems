#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

//using map
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	//난이도, 문제번호
	map<int, vector<int>> dictionary;

	for(int i = 0; i < N; i++)
	{
		int P = 0;
		int L = 0;
		cin >> P;
		cin >> L;

		dictionary[L].push_back(P);
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
			int level = 0;
			cin >> level;
			dictionary[level].push_back(num);
		}
		else if(command == "recommend")
		{
			if(num == 1)
			{
				auto iter = --dictionary.end();
				if(iter->second.size() > 1)
				{
					cout<<*max_element(iter->second.begin(), iter->second.end())<<"\n";
				}
				else
				{
					cout << iter->second[0] << "\n";
				}
			}
			else
			{
				auto iter = dictionary.begin();
				if (iter->second.size() > 1)
				{
					cout<<*min_element(iter->second.begin(), iter->second.end())<<"\n";
				}
				else
				{
					cout << iter->second[0] << "\n";
				}

			}
		}
		else if(command == "solved")
		{
			bool flag = false;

			for(auto iter = dictionary.begin(); iter != dictionary.end(); iter++)
			{
				for (int k = 0; k < iter->second.size(); k++)
				{
					if (iter->second[k] == num)
					{
						iter->second.erase(iter->second.begin() + k);

						if (iter->second.empty())
							dictionary.erase(iter);
					
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
		}
	}
	
	return 0;
}

//using priority queue
#include<iostream>
#include<queue>

using namespace std;

int problemList[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	//난이도, 문제번호
	priority_queue<pair<int, int>> pq1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;

	for(int i = 0; i < N; i++)
	{
		int P = 0;
		int L = 0;
		cin >> P;
		cin >> L;

		pq1.push({L, P});
		pq2.push({L, P});
		problemList[P] = L;
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
			int level = 0;
			cin >> level;
			pq1.push({ level, num });
			pq2.push({ level, num });
			problemList[num] = level;
		}
		else if(command == "recommend")
		{
			if(num == 1)
			{
				while(1)
				{
					if (problemList[pq1.top().second] == pq1.top().first) break;
					pq1.pop();
				}
				cout << pq1.top().second << "\n";
			}
			else
			{
				while (1)
				{
					if (problemList[pq2.top().second] == pq2.top().first) break;
					pq2.pop();
				}
				cout << pq2.top().second << "\n";
			}
		}
		else if(command == "solved")
		{
			problemList[num] = 0;
		}
	}

	return 0;

}
