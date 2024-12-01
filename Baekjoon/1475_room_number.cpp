#include<iostream>
#include<string>

using namespace std;

int arr[10] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num = 0;
	cin >> num;

	string str = to_string(num);
	int res = 0;

	for (int i = 0; i < str.length(); i++)
	{
		arr[str[i] - '0']++;
	}


	for(int i = 0; i < 10; i++)
	{
		if (i == 6 || i == 9) continue;

		if (res < arr[i])
			res = arr[i];
	}

	cout << max(res, (arr[6]+arr[9]+1)/2);
}