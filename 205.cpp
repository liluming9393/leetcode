/*Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters.No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
You may assume both s and t have the same length.*/
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
bool isIsomorphic(string s, string t);
int main()
{
	while (1)
	{
		string s;
		cin >> s;
		string t;
		cin >> t;
		bool result = isIsomorphic(s, t);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
bool isIsomorphic(string s, string t) 
{
	map<int, int> data;
	map<int, int>::iterator it;
	int flag = 1;
	if (s.size() == 0)
	{
		return true;
	}
	else
	{
		for (int i = 0; i < s.size(); i++)
		{
			it = data.find(s[i]);
			if (it != data.end())
			{
				if (t[i] != it->second)
				{
					flag = 0;
					i = s.size();
				}
			}
			else
			{
				data.insert(pair<int, int>(s[i], t[i]));
			}
		}
		if (flag == 0)
		{
			return false;
		}
		else
		{
			string temp = t;
			t = s;
			s = temp;
			data.clear();
			for (int i = 0; i < s.size(); i++)
			{
				it = data.find(s[i]);
				if (it != data.end())
				{
					if (t[i] != it->second)
					{
						flag = 0;
						i = s.size();
					}
				}
				else
				{
					data.insert(pair<int, int>(s[i], t[i]));
				}
			}
		}
		if (flag == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	return true;
}