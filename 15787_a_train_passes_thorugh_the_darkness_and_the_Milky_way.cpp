#include <iostream>

using namespace std;
#define MAX 0b1'1111'1111'1111'1111'1111
int N;
int M;
bool arr[MAX];

struct Train
{
	bool seats[22];
	int id = 0;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N; cin >> M;

	Train trains[100001] = {};

	for(int m = 0; m < M; m++)
	{
		int command = 0; cin >> command;
		if(command == 1)
		{
			int trainNum = 0; int pos = 0; cin >> trainNum; cin >> pos;

			if (trains[trainNum].seats[pos]) continue;

			trains[trainNum].seats[pos] = true;
		}
		else if(command == 2)
		{
			int trainNum = 0; int pos = 0; cin >> trainNum; cin >> pos;

			if (!trains[trainNum].seats[pos]) continue;

			trains[trainNum].seats[pos] = false;

		}
		else if(command == 3) //뒤로 한 칸씩
		{
			int trainNum = 0; cin >> trainNum;
			for(int i = 20; i >= 1; i--)
			{
				trains[trainNum].seats[i] = trains[trainNum].seats[i - 1];
			}
		}
		else //앞으로 한 칸씩
		{
			int trainNum = 0; cin >> trainNum;
			for (int i = 1; i <= 20; i++)
			{
				trains[trainNum].seats[i] = trains[trainNum].seats[i + 1];
			}
		}
	}

	//명령을 다 수행한 후에 track
	for(int i = 1; i <= N; i++)
	{
		int id = 0;
		for(int j = 1; j <= 20; j++)
		{
			if(trains[i].seats[j])
			{
				id += 1 << j;
			}
		}
		trains[i].id = id;
	}

	int res = 0;
	for(int i = 1; i <= N; i++)
	{
		if (!arr[trains[i].id]) res++;
		arr[trains[i].id] = true;
	}

	cout << res;
}