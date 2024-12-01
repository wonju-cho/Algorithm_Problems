#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

long long TimeConversion(string r, string t)
{
	int m = stoi(r.substr(5, 2));
	long long res = 0;
	int days = 0;

	for (int i = 1; i < m; i++)
	{
		days += daysInMonth[i];
	}

	days += stoi(r.substr(8));

	res += days * 24 * 60;
	res += stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3));

	return res;
}

struct Part
{
	string mPartName;
	long long time;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	string L = "";
	int F = 0;

	cin >> N;
	cin >> L;
	cin >> F;

	long long time = stoi(L.substr(0, 3)) * 1440 + stoi(L.substr(4, 2)) * 60 + stoi(L.substr(7, 2));

	map<string, vector<Part>> parts;
	map<string, long long> res = {};

	for (int i = 0; i < N; i++)
	{
		string rentDate, rentTime, pName, name;
		cin >> rentDate >> rentTime >> pName >> name;

		long long tempTime = TimeConversion(rentDate, rentTime);
		if (parts.count(name) && find_if(parts[name].begin(), parts[name].end(), [pName](const Part p) 
			{return p.mPartName == pName;}) != parts[name].end())
		{
			for (int j = 0; j < parts[name].size(); j++)
			{
				if (pName == parts[name][j].mPartName && parts[name][j].time < tempTime)
				{
					res[name] += (tempTime - parts[name][j].time) * F;
				}

				if (parts[name][j].mPartName == pName)
				{
					parts[name].erase(parts[name].begin() + j);
					break;
				}
			}

			if (parts[name].empty())
			{
				parts.erase(name);
			}
		}
		else
		{
			parts[name].push_back({ pName, tempTime + time });
		}
	}


	if (res.empty()) cout << "-1";
	else
	{
		for (auto r : res)
		{
			cout << r.first << " " << r.second << "\n";
		}
	}

}
