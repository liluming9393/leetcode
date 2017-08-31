//Write a function to find the longest common prefix string amongst an array of strings.
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
string longestCommonPrefix(vector<string>& strs);
int main()
{
	vector<string> strs = { "abcd", "abc", "abcf", "abcdef" };
	string result = longestCommonPrefix(strs);
	cout << result << endl;
	system("pause");
	return 0;
}
string longestCommonPrefix(vector<string>& strs) 
{
	string result;
	if (strs.size() == 0)
	{
		return result;
	}
	else
	{
		int len = strs[0].size();
		for (int i = 0; i < len; i++)
		{
			for (int j = 1; j < strs.size(); j++)
			{
				if (strs[j].size() < i)
				{
					return result;
				}
				else if (strs[j][i] != strs[0][i])
				{
					return result;
				}
			}
			result += strs[0][i];
		}
	}
	return result;
}