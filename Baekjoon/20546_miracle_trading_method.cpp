#include<iostream>

using namespace std;

struct Person
{
	int stock;
	int cash;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cash = 0; cin >> cash;

	Person jun({ 0, cash });
	Person sung({ 0, cash });
	int increaseCnt = 0;
	int decreaseCnt = 0;
	int prev = 0;
	int finalPrice = 0;

	for(int i = 0; i < 14; i++)
	{
		int price = 0; cin >> price;

		if (i == 13)
			finalPrice = price;
		else if (i == 0) prev = price;

		if (prev > price)
		{
			decreaseCnt++;
			increaseCnt = 0;
		}
		else if (prev < price)
		{
			increaseCnt++;
			decreaseCnt = 0;
		}

		if(increaseCnt >= 3) //다 팜
		{
			sung.cash += sung.stock * price;
			sung.stock = 0;
		}
		else if (decreaseCnt >= 3)
		{
			if (sung.cash / price > 0)
			{
				sung.stock += sung.cash / price;
				sung.cash -= sung.cash / price * price;
			}
		}

		if (jun.cash / price > 0)
		{
			jun.stock += jun.cash / price;
			jun.cash -= jun.cash / price * price;
		}

		prev = price;
	}

	jun.cash = jun.cash + finalPrice * jun.stock;
	sung.cash = sung.cash + finalPrice * sung.stock;

	if (jun.cash > sung.cash)
		cout << "BNP";
	else if (jun.cash < sung.cash)
		cout << "TIMING";
	else cout << "SAMESAME";

}