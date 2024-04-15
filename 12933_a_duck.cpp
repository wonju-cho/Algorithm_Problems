#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	string quack = "quack";
	int res = 0;
	bool flag = false;

	while(!str.empty())
	{
		//제일 처음 p의 위치를 찾기
		int qPos = 0;
		if(str.find('q')!= string::npos)
		{
			qPos = str.find('q');
		}
		else
		{
			flag = false;
			break;
		}

		//연속되는 소리를 지워주는 for문
		int cnt = 0;
		for(int i = qPos; i < str.length(); i++)
		{
			if (cnt == 5)
			{
				cnt = 0;
				flag = true;

				auto target = str.find('q', i);
				if (target != string::npos)
				{
					i = target;
				}
				else
				{
					break;
				}
			}

			if(str[i] == quack[cnt])
			{
				str.erase(str.begin() + i);
				i--;
				cnt++;
			}
		}

		//연속된 올바른 quack처리 해주기
		if (str.empty() && cnt == 5) flag = true;
		//남아있는 문장 체크 -> 문자는 다 체크했는데 ck같은 문장이 남아있는지
		else if(cnt > 0 && cnt != 5)
		{
			flag = false;
			break;
		}

		res++;
	}

	if (!flag) cout << -1;
	else cout << res;
}
