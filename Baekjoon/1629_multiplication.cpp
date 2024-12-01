#include<iostream>

using namespace std;

long long Func(long long A, long long B, long long C)
{
	if (B == 1) return A % C;

	long long val = Func(A, B / 2, C);
	val = val * val % C;

	if (B % 2 == 0) return val;

	return val * A % C;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A = 0;
	long long B = 0;
	long long C = 0;
	cin >> A; cin >> B; cin >> C;

	cout<<Func(A, B, C);
}