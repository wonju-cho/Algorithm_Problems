#include<iostream>
#include<map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;  cin >> N;
	map<string, int> organize;

	for (int i = 0; i < N; i++)
	{
		string file; cin >> file;
		auto dotPos = file.find('.');
		if(dotPos != string::npos)
		{
			organize[file.substr(dotPos + 1)]++;
		}
	}

	for(auto o : organize)
	{
		cout << o.first<<' '<< o.second << "\n";
	}
}