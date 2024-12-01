#include <iostream>

using namespace std;
#define MAX 10
#define RED 4

int b[MAX][MAX];

//To track the sum of the each col or row
int blue[6];
int green[6];

int score; int cnt;

void MoveBlock(int t, pair<int,int> p)
{
	if(t == 1)
	{
		//blue
		for (int x = RED; x <= 9; x++)
		{
			if (b[p.first][x] == 0)
			{
				if(x == 9)
				{
					b[p.first][x] = 1;
					blue[x - RED]++;
				}
				continue;
			}

			b[p.first][x - 1] = 1;
			blue[x - RED - 1]++;

			break;
		}

		//green
		for (int y = RED; y <= 9; y++)
		{
			if (b[y][p.second] == 0)
			{
				if(y == 9)
				{
					b[y][p.second] = 1;
					green[y - RED]++;
				}
				continue;
			}

			b[y - 1][p.second] = 1;
			green[y - RED - 1]++;

			break;
		}
	}
	else if(t == 2) //1x2 | (x,y), (x,y+1)
	{
		//blue
		for(int x = RED; x <= 8; x++)
		{
			if (b[p.first][x] == 0 && b[p.first][x + 1] == 0)
			{
				if(x + 1 == 9)
				{
					b[p.first][x] = 1;
					b[p.first][x + 1] = 1;
					blue[x - RED]++;
					blue[x - RED + 1]++;
				}

				continue;
			}

			b[p.first][x - 1] = 1;
			b[p.first][x + 1 - 1] = 1;
			blue[x - RED]++;
			blue[x - RED - 1]++;
			break;
		}

		//green
		for(int y = RED; y <= 9; y++)
		{
			if(b[y][p.second] == 0 && b[y][p.second + 1] == 0)
			{
				if(y == 9)
				{
					b[y][p.second] = 1;
					b[y][p.second + 1] = 1;
					green[y - RED] += 2;
				}
				continue;
			}

			b[y - 1][p.second] = 1;
			b[y - 1][p.second + 1] = 1;
			green[y - RED - 1] += 2;
			break;
		}
	}
	else //2x1 | (x,y), (x+1,y)
	{
		//blue
		for(int x = RED; x <= 9; x++)
		{
			if (b[p.first][x] == 0 && b[p.first + 1][x] == 0)
			{
				if(x == 9)
				{
					b[p.first][x] = 1;
					b[p.first + 1][x] = 1;
					blue[x - RED] += 2;
				}
				continue;
			}

			b[p.first][x - 1] = 1;
			b[p.first + 1][x - 1] = 1;
			blue[x - RED - 1] += 2;
			break;

		}

		//green
		for(int y = RED; y <= 8; y++)
		{
			if (b[y][p.second] == 0 && b[y + 1][p.second] == 0)
			{
				if(y == 8)
				{
					b[y][p.second] = 1;
					b[y + 1][p.second] = 1;
					green[y - RED]++;
					green[y - RED + 1]++;
				}
				
				continue;
			}

			b[y - 1][p.second] = 1;
			b[y + 1 - 1][p.second] = 1;
			green[y - RED]++;
			green[y - RED - 1]++;
			break;
		}

	}
}

void SpecialZoneCheck()
{
	int blueCnt = 0; int greenCnt = 0; int blueIdx = 0; int greenIdx = 0;
	for(int i = 0; i < 2; i++)
	{
		if (blue[i] > 0)
		{
			blueCnt++;
			blueIdx = i;
		}
		if (green[i] > 0) {
			greenCnt++;
			greenIdx = i;
		}
	}

	//remove cols
	if(blueCnt == 1)
	{
		blue[blueIdx] = 0;
		for (int y = 0; y < 4; y++)
		{
			b[y][9] = 0;
		}
	}
	else
	{
		for (int i = 0; i < blueCnt; i++)
		{
			blue[i] = 0;
			for (int y = 0; y < 4; y++)
			{
				b[y][9 - i] = 0;
			}
		}
	}


	//move the remaining blocks
	if(blueCnt > 0)
	{
		for(int x = 9 - blueCnt; x >= 4; x--)
		{
			int colCnt = 0;
			for(int y = 0; y < 4; y++)
			{
				if(b[y][x] != 0)
				{
					b[y][x] = 0;
					b[y][x + blueCnt] = 1;
					colCnt++;
				}
			}
			blue[x + blueCnt - RED] = colCnt;
		}
	}

	//remove rows
	if(greenCnt == 1)
	{
		green[greenIdx] = 0;
		for (int x = 0; x < 4; x++)
		{
			b[9][x] = 0;
		}
	}
	else
	{
		for (int i = 0; i < greenCnt; i++)
		{
			green[i] = 0;
			for (int x = 0; x < 4; x++)
			{
				b[9 - i][x] = 0;
			}
		}
	}
	
	//move the remaining blocks
	if(greenCnt > 0)
	{
		for (int y = 9 - greenCnt; y >= RED; y--)
		{
			int rowCnt = 0;
			for (int x = 0; x < 4; x++)
			{
				if (b[y][x] != 0)
				{
					b[y][x] = 0;
					b[y + greenCnt][x] = 1;
					rowCnt++;
				}
			}
			green[y + greenCnt - RED] = rowCnt;
		}
	}
}

void FillCheck()
{
	int cnt = 0; int start = 0;

	//blue
	for(int i = 5; i >= 2; i--)
	{
		if(blue[i] == 4)
		{
			cnt++;
			start = i;
			blue[i] = 0;
			for(int y = 0; y < 4; y++)
			{
				b[y][i + 4] = 0;
			}
		}
	}

	score += cnt;

	if(cnt > 0)
	{
		for(int x = start + RED - 1; x >= RED; x--)
		{
			int colCnt = 0;
			blue[x - RED] = 0;
			for(int y = 0; y < 4; y++)
			{
				if(b[y][x] != 0)
				{
					b[y][x] = 0;
					b[y][x + cnt] = 1;
					colCnt++;
				}
			}
			blue[x + cnt - RED] = colCnt;
		}
	}

	cnt = 0;

	//green
	for(int i = 5; i>= 2; i--)
	{
		if(green[i] == 4)
		{
			cnt++;
			start = i;
			green[i] = 0;
			for(int x = 0; x < 4; x++)
			{
				b[i + 4][x] = 0;
			}
		}
	}

	score += cnt;

	if (cnt > 0)
	{
		for (int y = start + RED - 1; y >= RED; y--)
		{
			int rowCnt = 0;
			green[y - RED] = 0;
			for(int x = 0; x < 4; x++)
			{
				if(b[y][x] != 0)
				{
					b[y][x] = 0;
					b[y + cnt][x] = 1;
					rowCnt++;
				}
			}
			green[y + cnt - RED] = rowCnt;
		}
	}

	SpecialZoneCheck();
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin>>N;
	for(int i = 0; i < N; i++)
	{
		int t = 0; int y = 0; int x = 0;
		cin >> t >> y >> x;

		MoveBlock(t, { y,x });

		FillCheck();
	}
	
	cout << score << "\n";

	for(int i = 0; i < 6; i++)
	{
		cnt += blue[i];
		cnt += green[i];
	}

	cout << cnt;

}