#include<set>
#include<vector>
#include<iostream>

using namespace std;

int T, cnt;
vector<vector<int>> g;
bool done[1000001];
bool v[1000001];

void DFS(int t, int curr)
{
	v[curr] = true;

	int next = g[t][curr];
	if(!v[next])
	{
		DFS(t, next);
	}
	else if(!done[next]) //방문을 했다는 거 자체가 사이클이 존재한다는 것! 그리고 이 일을 마친 적이 없을때만 사이클을 이루는 팀원의 수를 세기
	{
		for (int i = next; i != curr; i = g[t][i]) //이 for문이 팀원을 추적하는 for문. cycle을 이루고있으니 그냥 next에서 i != curr 까지 반복문을 시행하면 수를 셀 수 있음.
		{
			cnt++;
		}
		cnt++; //본인도 ++해주기
	}

	done[curr] = true;
}

void Initialize()
{
	cnt = 0;
	for(int i = 0; i < 1000001; i++)
	{
		done[i] = false;
		v[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> T;
	g.resize(T);

	for(int i = 0; i < T; i++)
	{
		cin >> N;
		g[i].resize(N + 1);
		for (int n = 1; n <= N; n++)
		{
			int temp = 0;
			cin >> temp;
			g[i][n] = temp;
		}
	}

	for(int t = 0; t < T; t++)
	{
		Initialize();
		for(int i = 1; i < g[t].size(); i++)
		{
			if(!v[i])
				DFS(t, i);
		}
		cout << g[t].size() - cnt - 1 << "\n";
	}
}