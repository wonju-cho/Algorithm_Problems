#include <iostream>
#include <queue>

using namespace std;

int main() {
	
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n = 0;
	cin >> n;

	queue<pair<int, int>> q;
    for(int i = 0; i < n; i++)
    {
    	int temp = 0;
    	cin >> temp;
    	q.push({ i + 1, temp });
    }
    
    cout<<"1 ";
    while(q.size() > 1)
    {
    	int num = q.front().second;
    	int cnt = abs(num);
    	q.pop();
    
    	if(num > 0)
    	{
    		for(int i  = 0; i < cnt - 1; i++)
    		{
    			q.push(q.front());
    			q.pop();
    		}
    	}
    	else
    	{
    		for(int i = 0; i < cnt; i++)
    		{
    			int back = q.back().first;
    
    			while(q.front().first != back)
    			{
    				q.push(q.front());
    				q.pop();
    			}
    		}
    	}
    
    	cout<<q.front().first<<" ";
    }

}