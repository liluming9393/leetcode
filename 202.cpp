/*Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process : Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example : 19 is a happy number

		  12 + 92 = 82
		  82 + 22 = 68
		  62 + 82 = 100
		  12 + 02 + 02 = 1*/
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
bool isHappy1(int n);
bool isHappy2(int n);
int main()
{
	int n;
	cin >> n;
	bool result = isHappy2(n);
	cout << result << endl;
	system("pause");
	return 0;
}
bool isHappy1(int n) 
{
	vector<int> temp;
	int count = 0;
	int sum = 0;
	while (sum != 1)
	{
		while (n != 0)
		{
			temp.push_back(n % 10);
			n = n / 10;
		}
		sum = 0;
		for (int i = 0; i < temp.size(); i++)
		{
			sum += temp[i] * temp[i];
		}
		n = sum;
		temp.clear();
		count++;
		if (count > 1000)
		{
			return false;
		}
	}
	return true;
}
bool isHappy2(int n)
{
	set<int> check;
	int sum = 0;
	while (sum != 1)
	{
		sum = 0;
		while (n != 0)
		{
			sum += (n % 10)*(n % 10);
			n = n / 10;
		}
		n = sum;
		int length = check.size();
		check.insert(sum);
		if (length == check.size())
		{
			return false;
		}
	}
	return true;
}