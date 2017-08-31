//Say you have an array for which the ith element is the price of a given stock on day i.
//If you were only permitted to complete at most one transaction(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int maxProfit(vector<int>& prices);
int main()
{
	int s[] = { 3, 5, 7, 2, 3, 8, 9 };
	vector<int> prices(s, s + 7);
	int result = maxProfit(prices);
	cout << result << endl;
	system("pause");
	return 0;
}
int maxProfit(vector<int>& prices)
{
	if (prices.size() == 0)
		return 0;
	int minprice = prices[0];
	int result = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		if (result < (prices[i] - minprice))
			result = prices[i] - minprice;
		if (prices[i] < minprice)
			minprice = prices[i];
	}
	return result;
}