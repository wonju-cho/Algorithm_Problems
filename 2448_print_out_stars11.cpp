#include <iostream>

using namespace std;

#define MAX 3075
int N;
char board[MAX][MAX * 2 - 1];

void Draw(int n, int y_, int x_)
{
    if(n == 3)
    {
        board[y_][x_] = '*';
        board[y_ + 1][x_ - 1] = '*'; board[y_ + 1][x_ + 1] = '*';

        for (int x = x_ - 2; x <= x_ + 2; x++)
        {
            board[y_ + 2][x] = '*';
        }

        return;
    }

    Draw(n / 2, y_ , x_);
    Draw(n / 2, y_ + n / 2, x_ - n / 2);
    Draw(n / 2, y_ + n / 2, x_ + n / 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N * 2 - 1; x++)
        {
            board[y][x] = ' ';
        }
    }

    Draw(N, 0, N - 1);

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N * 2 - 1; x++)
        {
            cout << board[y][x];
        }
        cout << "\n";
    }
}