#include iostream
#include queue

구슬이 겹칠 때, cnt를 세서 더 많이 이동한 애를 뒤로 이동시키기
파랑일때 빨강일때 방문 체크
using namespace std;
#define MAX 10

struct Marbles
{
	pairint, int red;
	pairint, int blue;
	int cnt = 0;
};

N height M width
int N, M;
char b[MAX][MAX];
bool v[MAX][MAX][MAX][MAX];
pairint, int dirs[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} }; clockwise
pairint, int red; pairint, int blue;
int res = 999;

void Game()
{
	queueMarbles q;
	q.push({ red, blue });

	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();

		if (curr.cnt  10) continue;

		for (int m = 0; m  4; m++)
		{
			auto tr = curr.red; auto tb = curr.blue;
			int rCnt = 0; int bCnt = 0;

			while (b[tr.first + dirs[m].first][tr.second + dirs[m].second] != '#')
			{
				tr.first += dirs[m].first; tr.second += dirs[m].second;

				if (b[tr.first][tr.second] == 'O')
				{
					tr = { -1,-1 };
					break;
				}

				rCnt++;
			}

			while(b[tb.first + dirs[m].first][tb.second + dirs[m].second] != '#')
			{
				tb.first += dirs[m].first; tb.second += dirs[m].second;
				if(b[tb.first][tb.second] == 'O')
				{
					tb = { -1,-1 };
					break;
				}
				bCnt++;
			}

			if (v[tr.first][tr.second][tb.first][tb.second]) continue;

			if (tb == pairint, int{-1, -1})
				continue;
			else if(tr == pairint,int{-1, -1})
			{
				if (curr.cnt + 1  11 && res  curr.cnt + 1)
					res = curr.cnt + 1;
				continue;
			}

			if(tr == tb)
			{
				if(rCnt  bCnt)
				{
					tr.first -= dirs[m].first; tr.second -= dirs[m].second;
				}
				else
				{
					tb.first -= dirs[m].first; tb.second -= dirs[m].second;
				}
			}

			v[tr.first][tr.second][tb.first][tb.second] = true;
			q.push({tr, tb, curr.cnt + 1});
		}
	}
}

int main() {

	ios_basesync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin  N  M;

	for (int y = 0; y  N; y++)
	{
		for (int x = 0; x  M; x++)
		{
			cin  b[y][x];
			if (b[y][x] == 'R')
				red = { y,x };
			else if (b[y][x] == 'B')
				blue = { y,x };
		}
	}

	Game();

	if (res == 999) cout  -1;
	else cout  res;
}