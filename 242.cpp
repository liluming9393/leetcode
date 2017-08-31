/*Given two strings s and t, write a function to determine if t is an anagram of s.
For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.*/
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
bool isAnagram1(string s, string t);
bool isAnagram2(string s, string t);
bool isAnagram3(string s, string t);
bool isAnagram4(string s, string t);
int main()
{
	string s = "anagram";
	string t = "nagaram";
	bool result = isAnagram4(s, t);
	cout << result << endl;
	system("pause");
	return 0;
}
bool isAnagram1(string s, string t) {
	int length = t.size();
	if (s.size() != t.size())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			int pos = s.find(t[0], 0);
			if (pos == std::string::npos)
			{
				return false;
			}
			else
			{
				s = s.erase(pos, 1);
				t = t.erase(0, 1);
			}
		}
	}
	return true;
}
bool isAnagram2(string s, string t)
{
	if (s.size() != t.size())
	{
		return false;
	}
	else
	{
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		if (s == t)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return true;
}
bool isAnagram3(string s, string t)
{
	multiset<char> s1;
	multiset<char>::iterator it;
	if (s.size() != t.size())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < s.size(); i++)
		{
			s1.insert(s[i]);
		}
		for (int i = 0; i < t.size(); i++)
		{
			it = s1.find(t[i]);
			if (it == s1.end())
			{
				return false;
			}
			else
			{
				s1.erase(s1.lower_bound(t[i]));
			}
		}
	}
	return true;
}
bool isAnagram4(string s, string t)
{
	int count[26] = {0};
	if (s.size() != t.size())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < s.size(); i++)
		{
			count[s[i] - 'a']++;
		}
		for (int i = 0; i < t.size(); i++)
		{
			count[t[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++)
		{
			if (count[i] != 0)
			{
				return false;
			}
		}
	}
	return true;
}