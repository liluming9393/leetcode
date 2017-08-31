/*The count - and - say sequence is the sequence of integers beginning as follows :
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.*/
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
string countAndSay(int n);
int main()
{
	while (1)
	{
		int n;
		cin >> n;
		string result = countAndSay(n);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
string countAndSay(int n)
{
	vector<int> data;
	vector<int> temp;
	int count = 1;
	string result;
	data.push_back(1);
	for (int k = 1; k < n; k++)
	{
		for (int i = 1; i < data.size(); i++)
		{
			if (data[i] != data[i - 1])
			{
				temp.push_back(count);
				temp.push_back(data[i - 1]);
				count = 1;
			}
			else
			{
				count++;
			}
		}
		temp.push_back(count);
		temp.push_back(data[data.size() - 1]);
		count = 1;
		data.clear();
		data = temp;
		temp.clear();
	}
	for (int i = 0; i < data.size(); i++)
	{
		result += (data[i] + '0'); 
	}
	return result;
}