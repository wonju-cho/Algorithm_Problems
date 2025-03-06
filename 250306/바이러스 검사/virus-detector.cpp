#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    //한 가게 당 팀장은 오직 한 명, 팀원은 여러명 가능
    //가게당 팀장 한 명은 무조건 필요.

    //n개의 식당 고객들의 체온을 측정하기 위해 필한 검사자 수의 최솟값

    int n;  cin>>n;
    vector<long> customers(n);
    for(int i = 0; i < n; i++)
    {
        cin>>customers[i];
    }

    long checkFromLeader = 0; long checkFromMember = 0;
    cin>>checkFromLeader>>checkFromMember;
    for(int i = 0; i < n; i++)
    {
        customers[i] = max(0L, customers[i] - checkFromLeader);
    }

    long res = 0;
    for(int i = 0; i < n; i++)
    {
        long memberCnt = customers[i] / checkFromMember;
        if(customers[i] % checkFromMember > 0)
            ++memberCnt;
        res += memberCnt + 1;
    }

    cout<<res;
    return 0;
}