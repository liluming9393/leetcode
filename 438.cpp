/*Given a string s and a non - empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20, 100.
The order of output does not matter.
Example 1:
Input :
s : "cbaebabacd" p : "abc"
Output :
[0, 6]
Explanation :
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2 :
Input :
s : "abab" p : "ab"
Output :
[0, 1, 2]
Explanation :
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".*/
#include<iostream>
#include<stdint.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
using namespace std;
vector<int> findAnagrams1(string s, string p);
vector<int> findAnagrams2(string s, string p);
int main()
{
	while (1)
	{
		string s;
		getline(cin, s);
		string p;
		getline(cin, p);
		vector<int> result = findAnagrams2(s, p);
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
vector<int> findAnagrams1(string s, string p)
{
	vector<int> result;
	if (s.size() < p.size())
	{
		return result;
	}
	multiset<char> data;
	multiset<char> check;
	for (int i = 0; i < p.length(); i++)
	{
		data.insert(p[i]);
		check.insert(s[i]);
	}
	for (int i = 0; i <=  (s.length() - p.length()); i++)
	{
		if (data == check)
		{
			result.push_back(i);
		}
		if (s[i] != s[i + p.length()])
		{
			check.erase(check.lower_bound(s[i]));
			check.insert(s[i + p.length()]);
		}
	}
	return result;
}
vector<int> findAnagrams2(string s, string p)
{
	vector<int> result;
	if (s.size() < p.size())
	{
		return result;
	}
	int data[26] = { 0 };
	int check[26] = { 0 };
	for (int i = 0; i < p.length(); i++)
	{
		data[p[i] - 'a']++;
		check[s[i] - 'a']++;
	}
	int flag;
	for (int i = 0; i <= (s.length() - p.length()); i++)
	{
		flag = 0;
		for (int j = 0; j < 26; j++)
		{
			if (data[j] != check[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			result.push_back(i);
		}
		if (s[i] != s[i + p.length()])
		{
			check[s[i] - 'a']--;
			check[s[i + p.length()]-'a']++;
		}
	}
	return result;
}
