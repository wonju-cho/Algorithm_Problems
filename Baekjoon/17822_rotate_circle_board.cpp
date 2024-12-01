#include <iostream>
#include <deque>

using namespace std;
#define MAX 52
int N; int M;
int b[MAX][MAX];
int temp[MAX][MAX];

void Adjacent(int i, int& sum, int& cnt, bool& flag)
{
	//원판 내에서 비교
	for (int m = 0; m < M; m++)
	{
		if(b[i][m] > 0)
		{
			cnt++;
			sum += b[i][m];
		}

		if (m == 0)
		{
			int compare = b[i][m];
			if (compare == -1) continue;
			if (b[i][m + 1] == compare)
			{
				temp[i][m + 1] = -1;
				temp[i][m] = -1;
				flag = true;
			}
			if (b[i][M - 1] == compare)
			{
				temp[i][M - 1] = -1;
				temp[i][m] = -1;
				flag = true;
			}
		}
		else if (m == M - 1)
		{
			int compare = b[i][m];
			if (compare == -1) continue;
			if (b[i][0] == compare)
			{
				temp[i][0] = -1;
				temp[i][m] = -1;
				flag = true;
			}
			if (b[i][m - 1] == compare)
			{
				temp[i][m - 1] = -1;
				temp[i][m] = -1;
				flag = true;
			}
		}
		else
		{
			int compare = b[i][m];
			if (compare == -1) continue;

			if (b[i][m - 1] == compare)
			{
				temp[i][m - 1] = -1;
				temp[i][m] = -1;
				flag = true;
			}
			if (b[i][m + 1] == compare)
			{
				temp[i][m + 1] = -1;
				temp[i][m] = -1;
				flag = true;
			}
		}
	}

	if (i == 1)
	{
		for(int m = 0; m < M; m++)
		{
			int compare = b[i][m];
			if (compare == -1) continue;
			if(compare == b[i+1][m])
			{
				temp[i + 1][m] = -1;
				temp[i][m] = -1;
				flag = true;
			}
		}
	}
	else if (i == N)
	{
		for (int m = 0; m < M; m++)
		{
			int compare = b[i][m];
			if (compare == -1) continue;
			if (compare == b[i - 1][m])
			{
				temp[i - 1][m] = -1;
				temp[i][m] = -1;
				flag = true;
			}
		}
	}
	else
	{
		for (int m = 0; m < M; m++)
		{
			int compare = b[i][m];
			if (compare == -1) continue;
			if (compare == b[i + 1][m])
			{
				temp[i + 1][m] = -1;
				temp[i][m] = -1;
				flag = true;
			}
			if (compare == b[i - 1][m])
			{
				temp[i - 1][m] = -1;
				temp[i][m] = -1;
				flag = true;
			}
		}
	}
}

void RotateBoard(int x, int d, int K)
{
	int idx = x;
	//시계
	if (d == 0)
	{
		while(idx <= N)
		{
			deque<int> dq;
			for (int m = 0; m < M; m++)
			{
				dq.push_back(b[idx][m]);
			}

			for (int k = 0; k < K; k++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}

			for(int i = 0; i < M; i++)
			{
				b[idx][i] = dq[i];
			}

			idx += x;
		}
	}
	else //반시계
	{
		while (idx <= N)
		{
			deque<int> dq;
			for(int m = 0; m < M ; m++)
			{
				dq.push_back(b[idx][m]);
			}

			for (int k = 0; k < K; k++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}

			for (int i = 0; i < M; i++)
			{
				b[idx][i] = dq[i];
			}
			idx += x;
		}
	}

	/*원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다.
	  그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
	  없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
	*/
	bool flag = false;
	int sum = 0; int cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			temp[i][j] = b[i][j];
		}
	}

	for(int i = 1; i <= N; i++)
	{
		Adjacent(i, sum, cnt, flag);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			b[i][j] = temp[i][j];
		}
	}

	if(!flag)
	{
		float average = (float)sum / (float)cnt;
		for (int i = 1; i <= N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				if (b[i][j] == -1) continue;
				if(average < b[i][j])
				{
					b[i][j] -= 1;
				}
				else if(average > b[i][j])
				{
					b[i][j] += 1;
				}
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++)
	{
		for(int m = 0; m < M; m++)
		{
			cin >> b[i][m];
		}
	}

	for(int t = 0; t < T; t++)
	{
		//번호가 xi의 배수인 원판을 di방향으로 ki칸 회전시킨다. di가 0인 경우는 시계 방향, 1인 경우는 반시계 방향이다.
		int x = 0; int d = 0; int k = 0; cin >> x >> d >> k;
		RotateBoard(x, d, k);
	}

	int res = 0;
	for (int i = 1; i <= N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if (b[i][j] != -1) res += b[i][j];
		}
	}

	cout << res;
}