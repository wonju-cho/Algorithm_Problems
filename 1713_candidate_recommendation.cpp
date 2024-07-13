#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
#define MAX 101

struct Student {
	int cnt = 0;
	int time = 0;
	int id = 0;
	int idx = 0;
};

//student idx 
vector<int> res;

//학생 추적
Student students[MAX];

//추천횟수에 따른 학생들
list<Student> track[1001];

pair<int, int> dirs[4] = { {-1,0}, {1,0}, {0,1}, {0,-1} };

//학생들이 추천을 시작하기 전에 모든 사진틀은 비어있다.
//어떤 학생이 특정 학생을 추천하면, 추천받은 학생의 사진이 반드시 사진틀에 게시되어야 한다.
//비어있는 사진틀이 없는 경우에는 현재까지 추천 받은 횟수가 가장 적은 학생의 사진을 삭제하고, 그 자리에 새롭게 추천받은 학생의 사진을 게시한다.
//이때, 현재까지 추천 받은 횟수가 가장 적은 학생이 두 명 이상일 경우에는 그러한 학생들 중 게시된 지 가장 오래된 사진을 삭제한다.
//현재 사진이 게시된 학생이 다른 학생의 추천을 받은 경우에는 추천받은 횟수만 증가시킨다.
//사진틀에 게시된 사진이 삭제되는 경우에는 해당 학생이 추천받은 횟수는 0으로 바뀐다.

void EraseListElement(int cnt, int id)
{
    if (track[cnt].empty()) return;

	if (track[cnt].front().id == id) {
		track[cnt].pop_front();
		return;
	}
	else if (track[cnt].back().id == id)
	{
		track[cnt].pop_back();
		return;
	}

	auto iter = track[cnt].begin();
	for (int i = 0; i < track[cnt].size(); i++, iter++)
	{
		if (iter->id == id)
		{
			track[cnt].erase(iter);
			break;
		}
	}
}

void Clear(int id)
{
	auto cnt = students[id].cnt;
	EraseListElement(cnt, id);

	students[id].cnt = 0;
	//students[id].time = -1;
	//students[id].id = -1;
	//students[id].idx = -1;
}

void Update(int time, int id, int idx)
{
	students[id].cnt++;
	students[id].time = time;
	students[id].id = id;
	students[id].idx = idx;
	track[students[id].cnt].push_back(students[id]);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int M = 0; cin >> N >> M; res.resize(N + 1);
	for (int m = 0; m < M; m++)
	{
		int id = 0; cin >> id; bool flag = false;
		for (int n = 1; n <= N; n++)
		{
			//어떤 학생이 특정 학생을 추천하면, 추천받은 학생의 사진이 반드시 사진틀에 게시되어야 한다.
			if (res[n] == 0)
			{
				flag = true;
				res[n] = id;
				Update(m, id, n);
				break;
			}
			//현재 사진이 게시된 학생이 다른 학생의 추천을 받은 경우에는 추천받은 횟수만 증가시킨다.
			else if (res[n] == id)
			{
				flag = true;
				EraseListElement(students[id].cnt, id);
				Update(students[id].time, id, n);
				break;
			}
		}

		if (!flag)
		{
			for (int i = 1; i <= M; i++)
			{
				if (track[i].empty()) continue;

				if (track[i].size() > 1)
				{
					//이때, 현재까지 추천 받은 횟수가 가장 적은 학생이 두 명 이상일 경우에는
					// 그러한 학생들 중 게시된 지 가장 오래된 사진을 삭제한다.
					int targetID = 0; int targetIdx = 0; int oldest = 100000;
					auto iter = track[i].begin();
					for (; iter != track[i].end(); iter++)
					{
						if (iter->time < oldest)
						{
							oldest = iter->time;
							targetID = iter->id;
							targetIdx = iter->idx;
						}
					}

					res[targetIdx] = id;
					Clear(targetID);
					Update(m, id, targetIdx);
					break;
				}
				else
				{
					//비어있는 사진틀이 없는 경우에는 
					//현재까지 추천 받은 횟수가 가장 적은 학생의 사진을 삭제하고, 
					//그 자리에 새롭게 추천받은 학생의 사진을 게시한다.
					int idx = track[i].begin()->idx;
					int deletedID = track[i].begin()->id;
					
					res[idx] = id;
					Clear(deletedID);
					Update(m, id, idx);
					break;
				}
			}
		}
	}

	sort(res.begin(), res.end());
	for (int i = 1; i <= N; i++)
	{
		if (res[i] == 0) continue;
		cout << res[i] << ' ';
	}

}