#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int year = 0; cin >> year;

	if (year % 4 == 0 && year % 100 != 0)
		cout << 1;
	else if (year % 400 == 0)
		cout << 1;
	else cout << 0;
}