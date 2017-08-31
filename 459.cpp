/*Given a non - empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
Example 1:
Input : "abab"
Output : True
Explanation : It's the substring "ab" twice.
Example 2 :
Input : "aba"
Output : False
Example 3 :
Input : "abcabcabcabc"
Output : True
Explanation : It's the substring "abc" four times. (And the substring "abcabc" twice.)*/
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
bool repeatedSubstringPattern(string str);
int main()
{
	string str;
	while (cin >> str)
	{
		bool result = repeatedSubstringPattern(str);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
bool repeatedSubstringPattern(string str) 
{
	if (str.size() == 1)
	{
		return false;
	}
	vector<int> data;
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == str[0])
		{
			data.push_back(i);
		}
	}
	if (data.size() == 0)
	{
		return false;
	}
	for (int i = 0; i < data.size(); i++)
	{
		int length = data[i];
		int j = length;
		int m = 0;
		while (j < str.size())
		{
			m = 0;
			for (int k = j; k < j + length; k++)
			{
				if (str[k] != str[m])
				{
					j = str.size();
					break;
				}
				m++;
			}
			j = j + length;
		}
		if (m == length)
		{
			return true;
		}
	}
	return false;
}