#include<iostream>

using namespace std;

int numArr[1000001] = {};
int mapping[2000001];
//bool mapping[2000001] can recue memory size

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size = 0;
	cin >> size;

	for(int i = 0; i < size; i++)
	{
		int num = 0;
		cin >> num;

		numArr[i] = num;
	}

	int sum = 0;
	cin >> sum;

	int res = 0;

	for(int i = 0; i < size; i++)
	{
		if (sum - numArr[i] > 0 && mapping[sum - numArr[i]] == numArr[i]) res++;
		mapping[numArr[i]] = sum - numArr[i];
	}

	cout << res;
}