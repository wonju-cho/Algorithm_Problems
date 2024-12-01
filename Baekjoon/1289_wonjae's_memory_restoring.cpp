using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T = 0; cin >> T;
	for (int t = 1; t <= T; t++)
	{
		string str = ""; cin >> str; int res = 0; char prev = '0';
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != prev)
			{
				res++;
			}
			prev = str[i];
		}

		cout << '#' << t << ' ' << res << '\n';
	}
}