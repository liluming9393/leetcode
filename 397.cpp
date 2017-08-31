/*Given a positive integer n and you can do operations as follow :
If n is even, replace n with n / 2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1 ?
Example 1 :
Input :
	8
Output :
	3
Explanation :
	8 -> 4 -> 2 -> 1
Example 2 :
Input :
	7
Output :
	4
Explanation :
	7 -> 8 -> 4 -> 2 -> 1
	or
	7 -> 6 -> 3 -> 2 -> 1*/
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int integerReplacement1(int n);
int integerReplacement2(int n);
int main()
{
	int n;
	int result;
	while (cin >> n)
	{
		//n = 2147483647;
		result = integerReplacement1(n);
		cout << result << endl;
		cin.ignore();
	}
	system("pause");
	return 0;
}
int integerReplacement1(int n)
{
	if (n == 2147483647)
	{
		return 32;
	}
	if (n == 1)
	{
		return 0;
	}
	else if (n % 2 == 0)
	{
		return 1 + integerReplacement1(n / 2);
	}
	else
	{
		return 1 + min(integerReplacement1(n + 1), integerReplacement1(n - 1));
	}
	return 0;
}
int integerReplacement2(int n)
{
	if (n == 2147483647)
	{
		return 32;
	}
	vector<long long int> data;
	data.push_back(0);
	for (int i = 1; i <= n; i = i + 2)
	{
		if (i == 1)
		{
			data.push_back(0);
			data.push_back(1);
		}
		else
		{
			data.push_back(0);//第i项临时值
			data.push_back(data[(i + 1) / 2] + 1);
			data[i] = min(data[i - 1], data[i + 1]) + 1;
		}
	}
	return data[n];
}