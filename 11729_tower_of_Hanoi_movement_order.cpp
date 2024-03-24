#include<iostream>

using namespace std;

void func(int a, int b, int n)
{
	if (n == 1)
	{
		cout << a << ' ' << b << "\n";
		return;
	}

	func(a, 6 - a - b, n - 1);
	cout << a << ' ' << b << "\n";
	func(6 - a - b, b, n - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K = 0;
	cin >> K;
	cout << (1 << K) - 1 << "\n";

	func(1, 3, K);
}