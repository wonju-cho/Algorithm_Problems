#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct Student {
    int idx = 0;
    int score = 0;
    string credit = "";
};
 
bool cmp(Student s1, Student s2) {
    return s1.score > s2.score;
}
 
int main() {
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    int T = 0; cin >> T;
    string credit[10] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };
    for (int t = 1; t <= T; t++)
    {
        int N = 0; int K = 0; cin >> N >> K;
        vector<Student> students;
        for (int i = 1; i <= N; i++)
        {
            int s1 = 0; int s2 = 0; int s3 = 0; cin >> s1 >> s2 >> s3;
            students.push_back({ i, (s1 * 35 / 100) + (s2 * 45 / 100) + (s3 * 20 / 100) });
        }
 
        sort(students.begin(), students.end(), cmp);
        int scale = N / 10; string res = "";
        for (int i = 0, idx = 0; i < students.size(); i++) {
            if (i != 0 && i % scale == 0)
            {
                idx++;
            }
            students[i].credit = credit[idx];
 
            if (students[i].idx == K)
            {
                res = students[i].credit;
                break;
            }
             
        }
 
        cout << '#' << t << ' ' << res << '\n';
    }
}