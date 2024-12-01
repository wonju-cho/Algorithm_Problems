#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

#define MAX 1000
int b[MAX];

void GetLargestNum(string& temp, int curr, int cnt, string& largest, unordered_set<string>& us) {
    if (curr == cnt)
    {
        if (temp > largest)
            largest = temp;

        return;
    }
    
    string str = temp + to_string(curr);
    if (us.count(str) == 1)
    {
        return;
    }
    us.insert(str);
    
    for (int i = 0; i < temp.length(); i++)
    {
        for (int j = i + 1; j < temp.length(); j++)
        {
            swap(temp[i], temp[j]);
            GetLargestNum(temp, curr + 1, cnt, largest, us);
            swap(temp[i], temp[j]);
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 0; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int num = 0; cin >> num; int cnt = 0; cin >> cnt;
        string temp = to_string(num);
        string largest;
        unordered_set<string> us;
        GetLargestNum(temp, 0, cnt, largest, us);
    
        cout << '#' << t << ' ' << largest << "\n";
    }
}