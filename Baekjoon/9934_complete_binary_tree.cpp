#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> num;
vector<int> tree[11];

void MakeTree(int s, int e, int depth)
{
	if(s == e)
	{
		tree[depth].push_back(num[s]);
		return;
	}

	int mid = (s + e) / 2;
	tree[depth].push_back(num[mid]);

	MakeTree(s, mid - 1, depth + 1);
	MakeTree(mid + 1, e, depth + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k = 0;
	cin >> k;

	int size = pow(2, k) - 1;

	for(int i = 0; i < size; i++)
	{
		int temp = 0;
		cin >> temp;
		num.push_back(temp);
	}

	MakeTree(0, size-1, 0);

	for(int i = 0; i < k; i++)
	{
		for (int j = 0; j < tree[i].size(); j++)
			cout << tree[i][j] << " ";
		cout << "\n";
	}
}