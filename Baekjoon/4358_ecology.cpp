#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	map<string, double> m;
	string temp = "";
	int size = 0;
	
	while(getline(cin, temp))
	{
		m[temp]++;
		size++;
	}
	
	for(auto iter = m.begin(); iter != m.end(); iter++)
	{
		iter->second = (iter->second / size) * 100;
		printf("%s %.4f\n", iter->first.c_str(), iter->second);
	}
}

