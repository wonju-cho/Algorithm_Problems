using namespace std;
#define MAX 9
int b[MAX][MAX];

bool IsValidSudoku() 
{
	//3x3 check
	pair<int, int> s = { 0,0 };
	for (int i = 0; i < 9; i++)
	{
		int check[10] = {};
		if (i != 0 && i % 3 == 0)
		{
			s.first += 3;
			s.second = 0;
		}
		
		pair<int, int> initialVal = s;
		for (; s.first < initialVal.first + 3; s.first++)
		{
			for (; s.second < initialVal.second + 3; s.second++)
			{
				check[b[s.first][s.second]]++;
				if (check[b[s.first][s.second]] > 1) return false;
			}
			s.second = initialVal.second;
		}
		s.second += 3;
		s.first = initialVal.first;
	}

	//col check
	for (int i = 0; i < 9; i++)
	{
		int check[10] = {};
		for (int j = 0; j < 9; j++)
		{
			check[b[j][i]]++;
			if (check[b[j][i]] > 1) return false;
		}
	}

	//row check
	for (int i = 0; i < 9; i++)
	{
		int check[10] = {};
		for (int j = 0; j < 9; j++)
		{
			check[b[i][j]]++;
			if (check[b[i][j]] > 1) return false;
		}
	}

	return true;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T = 0; cin >> T;

	for (int t = 1; t <= T; t++)
	{
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				cin >> b[y][x];
			}
		}

		if(IsValidSudoku())
			cout << '#' << t << " " << 1 << '\n';
		else
			cout << '#' << t << " " << 0 << '\n';
	}
}