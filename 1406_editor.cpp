#include<iostream>
#include<list>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str = "";
	cin >> str;
	int size = 0;
	cin >> size;

	std::list<char> list(str.begin(), str.end());
	auto iter = list.end();

	for(int i = 0; i < size; i++)
	{
		char command;
		cin >> command;

		if(command == 'P')
		{
			char c;
			cin >> c;

			iter = ++list.insert(iter, c);
		}
		else if(command == 'L')
		{
			if (iter == list.begin()) continue;
			--iter;
		}
		else if(command == 'D')
		{
			if (iter == list.end()) continue;
			++iter;
		}
		else if(command == 'B')
		{
			if (iter == list.begin()) continue;

			iter = list.erase(--iter);
		}
	}

	for(auto l : list)
	{
		cout << l;
	}
}