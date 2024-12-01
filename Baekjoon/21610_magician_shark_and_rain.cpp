#include <vector>
#include <iostream>

using namespace std;
#define MAX 52
int b[MAX][MAX];
bool v[MAX][MAX];
int N;
pair<int, int> movement[4] = {{-1, -1}, {-1, 1}, {1,-1}, {1,1}};
pair<int, int> dir[8] = { {0,-1}, {-1, -1}, {-1, 0}, {-1,1}, {0,1}, {1, 1}, {1,0}, {1, -1} };
vector<pair<int, int>> clouds;

void MoveCloud(int di, int si)
{
	for (int i = 0; i < clouds.size(); i++)
	{
		int dy = clouds[i].first + dir[di].first * si;
		int dx = clouds[i].second + dir[di].second * si;

		if (dy >= N) dy -= N;
		else if (dy < 0) dy += N;
		if (dx >= N) dx -= N;
		else if (dx < 0) dx += N;

		clouds[i] = { dy,dx };
		v[dy][dx] = true;
		b[dy][dx] += 1;
	}

}

void Flood()
{
	for (int i = 0; i < clouds.size(); i++)
	{
		int cnt = 0;
		for(int m = 0; m < 4; m++)
		{
			int dy = clouds[i].first + movement[m].first;
			int dx = clouds[i].second + movement[m].second;

			if (dy < 0 || dy >= N || dx < 0 || dx >= N) continue;

			if (b[dy][dx] > 0) cnt++;
		}
		b[clouds[i].first][clouds[i].second] += cnt;
	}
}

void GenerateCloud()
{
	clouds.clear();

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if(b[y][x] >= 2 && !v[y][x])
			{
				v[y][x] = true;
				b[y][x] -= 2;
				clouds.push_back({ y,x });
			}
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			v[y][x] = false;
		}
	}

}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M = 0;
	cin >> N >> M;

	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < N; x++)
		{
			cin >> b[y][x];
		}
	}

	clouds.push_back({ N - 1, 0 });
	clouds.push_back({ N - 1, 1 });
	clouds.push_back({ N - 2, 0 });
	clouds.push_back({ N - 2, 1 });

	for(int i = 0; i < M; i++)
	{
		int di = 0; int si = 0; cin >> di >> si;

		//구름이 이동하고 //구름 칸에 비 1씩 내리고 구름 사라짐
		MoveCloud(di - 1, si % N);

		//물이 증가한 칸에 물복사 버그
		Flood();

		//구름이 있었던 칸을 제외하고 물의 양이 2 이상인 칸에 구름이 생기고 물의 양 2만큼 줄어듦
		GenerateCloud();
	}

	int res = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			res += b[y][x];
		}
	}
	cout << res;
}