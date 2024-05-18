#include <iostream>
#include <string>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; cin >> N;
	for (int i = 1; i <= N; i++)
	{
		string str = to_string(i); bool flag = false; int cnt = 0;
		for (auto s : str)
		{
			if (s == '3' || s == '6' || s == '9')
			{
				flag = true;
				cnt++;
			}
		}

		if (flag)
		{
			while (cnt > 0)
			{
				cout << '-';
				cnt--;
			}
		}
		else {
			cout << str;
		}
		cout << ' ';
	}
    
	return 0;
}