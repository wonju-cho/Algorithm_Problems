#include <iostream>
#include <unordered_map>

using namespace std;
#define MAX 2187

int N;
int matrix[MAX][MAX];
//-1, 0, 1
unordered_map<int, int> res;

void CountPaper(int len, int y_, int x_)
{
	//Base condition
	if(len == 1)
	{
		res[matrix[y_][x_]]++;
		return;
	}

	//check the papers have same number
	int number = matrix[y_][x_];
	bool flag = false;
	for (int y = y_; y < y_ + len; y++)
	{
		for (int x = x_; x < x_ + len; x++)
		{
			if(number != matrix[y][x])
			{
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	//Recursion.. divide into 9 pieces
	if(flag)
	{
		int tempY = y_;
		int tempX = x_;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				CountPaper(len / 3, tempY, tempX);
				tempX += len / 3;
			}
			tempY += len / 3;
			tempX = x_;
		}
	}
	else
	{
		res[number]++;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for(int y = 0; y < N; y++)
	{
		for(int x = 0; x < N; x++)
		{
			int temp = 0; cin >> temp;
			matrix[y][x] = temp;
		}
	}

	CountPaper(N, 0, 0);

	cout << res[-1] << "\n";
	cout << res[0] << "\n";
	cout << res[1] << "\n";
}
