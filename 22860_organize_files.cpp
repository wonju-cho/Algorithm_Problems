#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
struct Folder
{
	vector<string> files;
	vector<Folder*> childs;
};

int N; int M; int Q;

pair<int,int> FileCnt(Folder f, pair<int,int>& res, unordered_set<string>& s)
{
	for(auto f : f.files)
	{
		s.insert(f);
	}
	res.second += f.files.size();

	for(auto c: f.childs)
	{
		res = FileCnt(*c, res, s);
	}
	return { s.size(), res.second};
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, Folder> folders;
	cin >> N >> M;
	for(int i = 0; i < N + M; i++)
	{
		string P; string F; int C; cin >> P >> F >> C;
		if (C == 1)
		{
			folders[P].childs.push_back(&folders[F]);
		}
		else
		{
			folders[P].files.push_back(F);
		}
	}

	cin >> Q;
	for(int i = 0; i < Q; i++)
	{
		string query = ""; cin >> query; string path = "";
		for(int i = 0; i < query.length(); i++)
		{
			if(query[i] == '/')
			{
				path.clear();
			}
			else
			{
				path += query[i];
			}
		}
		pair<int, int> res = {}; unordered_set<string> s;
		res = FileCnt(folders[path], res, s);
		cout << res.first << " " << res.second<<"\n";
	}
}