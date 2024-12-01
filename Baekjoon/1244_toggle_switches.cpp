#include<iostream>

using namespace std;

#define MAX 101
bool switches[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; cin >> N;

	for(int n = 1; n <= N; n++)
	{
		int temp = 0; cin >> temp;
		switches[n] = temp;
	}

	int S = 0; cin >> S;
	for(int s = 0; s < S; s++)
	{
		int sex = 0; int num = 0; cin >> sex; cin >> num;
		if(sex == 1) //남: 받은수의 배수 스위치 toggle
		{
			int multiplier = 1;
			int temp = num;
			while(num <= N)
			{
				switches[num] = !switches[num];
				multiplier++;
				num = temp * multiplier;
			}
		}
		else //여
		{
			switches[num] = !switches[num];
			int l = num - 1; int r = num + 1;
			while(switches[l] == switches[r])
			{
				if (l < 1 || r > N) break;
				switches[l] = !switches[l];
				switches[r] = !switches[r];
				l--;
				r++;
			}
		}
	}

	int cnt = 0;
	for(int n = 1; n <= N; n++, cnt++)
	{
		if (cnt == 20)
		{
			cout << "\n";
			cnt = 0;
		}
		cout << switches[n] << " ";
	}
}