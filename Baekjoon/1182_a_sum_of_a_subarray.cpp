#include <iostream>

using namespace std;
//간단한 합을 구하는것에 비해 복잡하고 
//백트랙킹의 개념에 완전히 부합하는 코드가 아닌 듯
int N; int S; int res = 0;
int arr[20];
bool v[20];

void SubArray(int curr, int sum)
{
	if (sum == S)
	{
		res++;
	}

	for(int i = curr; i < N; i++)
	{
		if(!v[i])
		{
			v[i] = true;
			SubArray(i, sum + arr[i]);
			v[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N; cin >> S;

	for(int i = 0; i < N; i++)
	{
		int temp = 0; cin >> temp;
		arr[i] = temp;
	}

	SubArray(0, 0);

	if (S == 0)
		res -= 1;

	cout << res;
}

//직관적임 -> 이 선택지에서 이것을 선택할 것인지 선택하지 않을것인지
//백트랙킹을 잘 사용한 코드
using namespace std;

int n, s;
int arr[30];
int cnt = 0;
void func(int cur, int tot){
  if(cur == n){
    if(tot == s) cnt++;
    return;
  }
  func(cur+1, tot);
  func(cur+1, tot+arr[cur]);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  func(0, 0);
  if(s == 0) cnt--;
  cout << cnt;
}