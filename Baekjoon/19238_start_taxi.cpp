#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 22
struct Taxi
{
	pair<int, int> p;
	int gas = 0;
};

int N; int M;
pair<int, int> movement[4] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
Taxi taxi;
int b[MAX][MAX];
int adj[MAX][MAX];
bool v[MAX][MAX];
bool flag;
vector<pair<int,int>> passengerIdx;

int BFS2(Taxi taxi, pair<int, int> d)
{
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			v[y][x] = false;
		}
	}

	queue<pair<Taxi, int>> q;
	q.push({ taxi, 0 });
	v[taxi.p.first][taxi.p.second] = true;

	while(!q.empty())
	{
		auto p = q.front().first.p;
		int gas = q.front().first.gas;
		int dist = q.front().second;
		q.pop();

		if(gas < 0)
		{
			flag = true;
			return -1;
		}

		if(p == d)
		{
			return dist;
		}

		for (int m = 0; m < 4; m++)
		{
			int dy = p.first + movement[m].first;
			int dx = p.second + movement[m].second;

			if (dy < 1 || dy > N || dx < 1 || dx > N) continue;

			if (v[dy][dx] || b[dy][dx] == 1) continue;

			v[dy][dx] = true;

			q.push({ {{dy,dx}, gas - 1}, dist + 1 });
		}
	}

	return -1;
}

//택시의 현재 위치를 기준으로 adj의 거리를 구하는 함수
bool BFS(pair<int,int> p)
{
	//백준이 태울 승객을 고를 때는 현재 위치에서 최단거리가 가장 짧은 승객을 고른다.
	//택시와 승객이 같은 위치에 서 있으면 그 승객까지의 최단거리는 0이다.
	//한 승객을 목적지로 성공적으로 이동시키면, 그 승객을 태워 이동하면서 소모한 연료 양의 두 배가 충전된다.
	//이동하는 도중에 연료가 바닥나면 이동에 실패하고, 그 날의 업무가 끝난다.
	//승객을 목적지로 이동시킨 동시에 연료가 바닥나는 경우는 실패한 것으로 간주하지 않는다.

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			v[y][x] = false;
			adj[y][x] = 0;
		}
	}

	queue<pair<Taxi, int>> q;
	q.push({ taxi,0 });
	v[p.first][p.second] = true;
	int min = 9999;
	pair<int, int> res = { -1,-1 };

	while(!q.empty())
	{
		auto p = q.front().first.p;
		int gas = q.front().first.gas;
		int dist = q.front().second;
		q.pop();

		if(min == 9999 && gas < 0)
		{
			flag = true;
			return false;
		}

		if(dist < min && b[p.first][p.second] > 1)
		{
			min = adj[p.first][p.second];
			res = p;
		}
		else if(dist == min  && b[p.first][p.second] > 1)
		{
			//그런 승객이 여러 명이면 그중 행(row) 번호가 가장 작은 승객을,
			//그런 승객도 여러 명이면 그중 열(col) 번호가 가장 작은 승객을 고른다.
			if(res.first > p.first)
			{
				res = p;
			}
			else if(res.first == p.first)
			{
				if(res.second > p.second)
				{
					res = p;
				}
			}
		}

		for(int m = 0; m < 4; m++)
		{
			int dy = p.first + movement[m].first;
			int dx = p.second + movement[m].second;

			if (dy < 1 || dy > N || dx < 1 || dx > N) continue;

			if (v[dy][dx] || b[dy][dx] == 1) continue;

			v[dy][dx] = true;

			adj[dy][dx] = dist + 1;
			q.push({ { {dy,dx}, gas - 1 }, adj[dy][dx] });
		}
	}

	if(res != pair<int,int>{-1,-1})
	{
		//taxi 이동, passenger 보드에서 제거, 연료 없애고 다시 충전
		taxi.gas -= min;
		taxi.p = res;

		const int moved = BFS2(taxi, passengerIdx[b[res.first][res.second]]);
		if (moved == -1) return false;

		taxi.gas -= moved;
		taxi.gas += moved * 2;
		taxi.p = passengerIdx[b[res.first][res.second]];
		b[res.first][res.second] = 0;

		return true;
	}

	return false;
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	passengerIdx.resize(405);

	cin >> N >> M >> taxi.gas;
	for(int y = 1; y <= N; y++)
	{
		for(int x = 1; x <= N; x++)
		{
			cin >> b[y][x];
		}
	}

	cin >> taxi.p.first >> taxi.p.second;

	for(int m = 0; m < M; m++)
	{
		// 출발지의 행과 열 번호, 그리고 목적지의 행과 열 번호
		pair<int, int> s; pair<int, int> d;
		cin >> s.first >> s.second >> d.first >> d.second;
		b[s.first][s.second] = m + 2;
		passengerIdx[m + 2] = d;
	}

	while(M > 0 && BFS(taxi.p))
	{
		M--;
	}

	if (flag || M >= 1) //승객을 다 태우지 못했는데 연료가 바닥 난 경우
		cout << -1;
	else
		cout<<taxi.gas;
}