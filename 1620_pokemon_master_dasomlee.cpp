#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, int> pokemap1;
	unordered_map<int, string> pokemap2;

	int size = 0;
	cin >> size;
	int goal = 0;
	cin >> goal;

	for(int i = 0; i < size; i++)
	{
		string temp = "";
		cin >> temp;
		pokemap1[temp] = i + 1;
		pokemap2[i + 1] = temp;
	}

	for(int i = 0; i < goal; i++)
	{
		string temp = "";
		cin >> temp;
		if(isalpha(temp[0]))
		{
			cout << pokemap1[temp] << "\n";
		}
		else
		{
			cout << pokemap2[stoi(temp)] << "\n";
		}
	}

}