#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 22

pair<int, int> movement[4] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

struct Shark
{
    void LevelUp()
    {
        level++;
        cnt = 0;
    }

    pair<int, int> pos;
    int level = 2;
    int cnt = 0;
    int move = 0;
};

Shark shark;
int N;
int b[MAX][MAX];
int adj[MAX][MAX];
bool v[MAX][MAX];

bool FindPrey(pair<int, int> p)
{
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            adj[y][x] = 0;
            v[y][x] = false;
        }
    }

    //pos, distance
    queue<pair<pair<int,int>, int>> q;
    q.push({ p,0 });
    v[p.first][p.second] = true;
    b[p.first][p.second] = 0;

    vector<pair<int, int>> goal;
    int minDist = 999;

	while(!q.empty())
    {
        auto pos = q.front().first;
        int dist = q.front().second;
        q.pop();

        for(int m = 0; m < 4; m++)
        {
            int dy = pos.first + movement[m].first;
            int dx = pos.second + movement[m].second;

            if (dy < 0 || dy >= N || dx < 0 || dx >= N) continue;

            if(v[dy][dx]) continue;

            if (b[dy][dx] > shark.level) continue;

            v[dy][dx] = true;
            adj[dy][dx] = dist + 1;

        	if(b[dy][dx] != 0 && b[dy][dx] < shark.level) //먹을수 있는 물고기
            {
                if(adj[dy][dx] < minDist)
                {
                    goal.clear();
                    minDist = adj[dy][dx];
                }

                if(adj[dy][dx] == minDist)
                {
                    goal.push_back({ dy,dx });
                }
            }
            q.push({ {dy,dx}, adj[dy][dx]});
        }
    }
    
    if(!goal.empty())
    {
        if(goal.size() == 1)
        {
            shark.pos = goal[0];
        }
        else
        {
            //제일 왼쪽,위쪽 에 있는 물고기 찾기
            sort(goal.begin(), goal.end());
            shark.pos = goal[0];
        }

        shark.move += minDist;
        shark.cnt++;
        if (shark.cnt == shark.level) shark.LevelUp();
        return true;
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    bool flag = false;
    for(int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> b[y][x];

            if (b[y][x] == 9)
            {
                shark.pos = { y,x };
	            continue;
            }

            if (!flag && b[y][x] != 0) {
                flag = true;
            }
	    }
    }

    if(!flag)
    {
        cout << 0;
        return 0;
    }

    while(FindPrey(shark.pos)){}

    cout << shark.move;
}