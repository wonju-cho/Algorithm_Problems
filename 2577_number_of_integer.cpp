#include<iostream>
#include<string>

using namespace std;

int arr[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int res = 1;
	int temp = 0;

	for (int i = 0; i < 3; i++)
	{
		cin >> temp;
		res *= temp;
	}

	string str = to_string(res);

	for(int i = 0; i < str.length(); i++)
	{
		arr[str[i] - '0']++;
	}

	for(int i = 0; i < 10; i++)
	{
		cout << arr[i] << "\n";
	}
}

//정답코드
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C;
	cin >> A >> B >> C;
	int t=A*B*C;
	int d[10] = {};
	// 계산 결과를 자릿수별로 확인하여 저장
	while (t>0) {
		d[t%10]++;
		t/=10;
	}
	for (int i=0; i<10; ++i) cout << d[i] << '\n';
}