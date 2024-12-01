#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 200
struct Tree
{
	pair<int, int> pos;
	int age;
};

int initial[10][10];
int b[10][10];
int N; int M;
pair<int, int> movement[8] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
vector<queue<Tree>> currTree(MAX);
vector<Tree> deadTree;

void Spring()
{
	vector<vector<Tree>> update(MAX);

	//본인 나이만큼 양분먹고 나이 + 1, 양분 못먹으면 죽음
	for (int i = 0; i < MAX; i++)
	{
		queue<Tree> q = currTree[i];
		while (!q.empty())
		{
			auto curr = q.front();
			q.pop();
			currTree[i].pop();

			if (b[curr.pos.first][curr.pos.second] >= curr.age)
			{
				b[curr.pos.first][curr.pos.second] -= curr.age;
				update[i + 1].push_back({ {curr.pos}, i + 1 });
			}
			else
			{
				deadTree.push_back(curr);
			}
		}
	}

	for(int i = 0; i < MAX; i++)
	{
		for (auto up : update[i])
		{
			currTree[i].push(up);
		}
	}
}

void Summer()
{
	//봄에 죽은 나무 양분으로, 나이 / 2 만큼 양분
	for (auto dt : deadTree)
	{
		b[dt.pos.first][dt.pos.second] += dt.age / 2;
	}
	deadTree.clear();
}

void Fall()
{
	//번식 나무 나이가 5 배수면 8칸에 나이 1 인 나무 생김
	vector<Tree> temp;
	for (int i = 5; i < MAX; i += 5)
	{
		queue<Tree> q = currTree[i];
		while (!q.empty())
		{
			auto curr = q.front();
			q.pop();

			for (int m = 0; m < 8; m++)
			{
				int dy = curr.pos.first + movement[m].first;
				int dx = curr.pos.second + movement[m].second;

				if (dy < 0 || dy >= N || dx < 0 || dx >= N) continue;

				temp.push_back({ {dy,dx}, 1 });
			}
		}
	}

	for(auto t : temp)
	{
		currTree[1].push(t);
	}
}

void Winter()
{
	//양분 공급
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			b[y][x] += initial[y][x];
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K = 0;
	cin >> N >> M >> K;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> initial[y][x];
			b[y][x] = 5;
		}
	}

	for (int m = 0; m < M; m++)
	{
		int y = 0; int x = 0; int z = 0; cin >> y >> x >> z;
		currTree[z].push({ {--y,--x}, z });
	}


	for (int k = 0; k < K; k++)
	{
		Spring();
		Summer();
		Fall();
		Winter();
	}

	int res = 0;
	for (auto ct : currTree)
		res += ct.size();

	cout << res;
}