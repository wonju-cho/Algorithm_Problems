#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
#define MAX 101

int b[MAX][MAX];
int b2[MAX][MAX];
int R; int C; int K;

bool cmp(pair<int,int>& p1, pair<int,int>& p2)
{
    if (p1.second == p2.second) return p1.first < p2.first;

    return p1.second < p2.second;
}

void CopyBoard(int Y, int X)
{
    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            b[y][x] = b2[y][x];
        }
    }

    for (int y = 0; y < Y; y++)
    {
        for (int x = 0; x < X; x++)
        {
            b2[y][x] = 0;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> K;

    for(int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++) 
        {
            cin >> b[y][x];
        }
    }

    int res = 0;
    int currRow = 3; int currCol = 3;
    while(res <= 100)
    {
        if (b[R - 1][C - 1] == K)
        {
            cout << res;
            break;
        }

        if(currRow >= currCol) // R: 행을 읽어서 행(x증가)으로 정리 -> 열이 늘어남
        {
            int row = currRow; //y 몇개 있는지
            int col = currCol; //x 몇개 있는지
            currCol = 0;
            for(int y = 0; y < row; y++)
            {
                unordered_map<int, int> track;
                for (int x = 0; x < col; x++)
                {
                    if (b[y][x] == 0) continue;
                    track[b[y][x]]++;
                }

                vector<pair<int, int>> temp;
                for (auto t : track)
                {
                    temp.push_back({ t.first, t.second });
                }

                if (currCol < temp.size() * 2)
                {
                    currCol = temp.size() * 2;
                }

                sort(temp.begin(), temp.end(), cmp);
                int idx = 0;
                for(auto t : temp)
                {
                    b2[y][idx++] = t.first;
                    b2[y][idx++] = t.second;
                }
            }
            CopyBoard(currRow, currCol);
        }
        else //C: 열을 읽어서 열(y증가)으로 정리 -> 행이 늘어남
        {
            int row = currRow; //y 몇개 있는지
            int col = currCol; //x 몇개 있는지
            currRow = 0;
            for (int x = 0; x < col; x++)
            {
                unordered_map<int, int> track;
                for (int y = 0; y < row; y++)
                {
                    if (b[y][x] == 0) continue;
                    track[b[y][x]]++;
                }

                vector<pair<int, int>> temp;
                for (auto t : track)
                {
                    temp.push_back({ t.first, t.second });
                }

                if (currRow < temp.size() * 2)
                {
                    currRow = temp.size() * 2;
                }

                sort(temp.begin(), temp.end(), cmp);
                int idx = 0;
                for (auto t : temp)
                {
                    b2[idx++][x] = t.first;
                    b2[idx++][x] = t.second;
                }
            }
            CopyBoard(currRow, currCol);
        }
        res++;
    }

    if(res > 100)
    {
        cout << -1;
    }
}