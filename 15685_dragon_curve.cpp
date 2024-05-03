#include <iostream>
#include <vector>

using namespace std;
struct Point
{
	pair<int, int> pos;
	int dir;
	int g;
};

#define MAX 101
bool b[MAX][MAX];
pair<int, int> movement[4] = { {0,1},{-1,0},{0,-1},{1,0} };

void GenerateDragonCurve(Point curves)
{
	vector<int> temp;
	temp.push_back(curves.dir);

	for(int g = 0; g < curves.g; g++)
	{
		int size = temp.size();
		for(int i = size; i > 0; i--)
		{
			temp.push_back((temp[i-1] + 1) % 4);
		}
	}

	pair<int, int> pos = curves.pos;
	b[pos.first][pos.second] = true;
	for(auto t : temp)
	{
		pos.first = pos.first + movement[t].first;
		pos.second = pos.second + movement[t].second;

		b[pos.first][pos.second] = true;
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; cin >> N;
	Point curves[21];
	for (int n = 0; n < N; n++)
	{
		int x = 0; int y = 0; int d = 0; int g = 0; cin >> x >> y >> d >> g;
		curves[n] = { {y,x},d, g };
	}

	for (int n = 0; n < N; n++)
	{
		GenerateDragonCurve(curves[n]);
	}
	
	int res = 0;
	for (int y = 0; y < MAX; y++)
	{
		for (int x = 0; x < MAX; x++)
		{
			if(b[y][x])
			{
				int cnt = 0;
				if (x + 1 < MAX && b[y][x + 1]) cnt++;
				if (y + 1 < MAX && b[y + 1][x]) cnt++;
				if (x + 1 < MAX && y + 1 < MAX && b[y + 1][x + 1]) cnt++;

				if(cnt == 3)
				{
					res++;
				}
			}
		}
	}

	cout << res;

}