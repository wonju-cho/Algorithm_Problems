#include<iostream>
#include<list>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size = 0;
	cin >> size;

	list<char> list;

	for(int i = 0; i < size; i++)
	{
		string str = "";
		cin >> str;

		auto iter = list.end();
		for(int j = 0; j < str.length(); j++)
		{
			if(str[j] == '<')
			{
				if (iter == list.begin()) continue;
				--iter;
			}
			else if(str[j] == '>')
			{
				if (iter == list.end()) continue;
				++iter;
			}
			else if(str[j] == '-')
			{
                if (iter == list.begin()) continue;
				iter = list.erase(--iter);
			}
			else
			{
				iter = ++list.insert(iter, str[j]);
			}
		}

		for(auto l : list)
		{
			cout << l;
		}
		cout << "\n";

		list.clear();
	}

}