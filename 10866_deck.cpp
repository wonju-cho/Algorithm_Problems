#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n = 0;
	cin >> n;

	deque<int> dq;

	for(int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		if(str == "push_back")
		{
			int temp = 0;
			cin >> temp;
			dq.push_back(temp);
		}
		else if (str == "push_front")
		{
			int temp = 0;
			cin >> temp;
			dq.push_front(temp);
		}
		else if (str == "front")
		{
			if (dq.empty()) cout<<"-1\n";
			else
			{
				cout<<dq.front()<<"\n";
			}
		}
		else if (str == "back")
		{
			if (dq.empty()) cout<<"-1\n";
			else
			{
				cout<<dq.back()<<"\n";;
			}
		}
		else if (str == "size")
		{
			cout<<dq.size()<<"\n";
		}
		else if (str == "empty")
		{
			if (dq.empty()) cout<<"1\n";
			else cout<<"0\n";
		}
		else if (str == "pop_front")
		{
			if (dq.empty()) cout<<"-1\n";
			else
			{
				int temp = dq.front();
				dq.pop_front();
				cout<<temp<<"\n";
			}
		}
		else if (str == "pop_back")
		{
			if (dq.empty()) cout<<"-1\n";
			else
			{
				int temp = dq.back();
				dq.pop_back();
				cout<<temp<<"\n";
			}
		}
	}

}