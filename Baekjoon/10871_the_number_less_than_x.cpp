#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size = 0;
	cin >> size;
	int limit = 0;
	cin >> limit;

	for(int i = 0; i < size; i++)
	{
		int temp = 0;
		cin >> temp;
		if(temp < limit)
		{
			cout << temp << " ";
		}
	}

}

