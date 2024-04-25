#include <iostream>

using namespace std;
int building[500];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int H; int W; cin >> H; cin >> W;
	for (int i = 0; i < W; i++)
	{
		cin >> building[i];
	}

	int left = 0; int right = W - 1; int leftMax = building[left]; int rightMax = building[right];
	int res = 0;
	while(left <= right)
	{
		if(leftMax <= rightMax)
		{
			if(building[left] < leftMax)
			{
				res += leftMax - building[left];
			}

			if (building[left] > leftMax)
				leftMax = building[left];

			left++;
		}
		else
		{
			if (building[right] < rightMax)
			{
				res += rightMax - building[right];
			}

			if (building[right] > rightMax)
				rightMax = building[right];

			right--;
		}
	}

	cout << res;

}