/*Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines; otherwise, it will return false.
Each letter in the magazine string can only be used once in your ransom note.
Note:
You may assume that both strings contain only lowercase letters.
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true*/
#include<iostream>
#include<stdint.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<stack>
#include<string>
using namespace std;
bool canConstruct1(string ransomNote, string magazine);
bool canConstruct2(string ransomNote, string magazine);
int main()
{
	while (1)
	{
		string ransomNote;
		getline(cin, ransomNote);
		string magazine;
		getline(cin, magazine);
		bool result = canConstruct2(ransomNote, magazine);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
bool canConstruct1(string ransomNote, string magazine)
{
	multiset<char> s;
	multiset<char>::iterator it;
	for (int i = 0; i < magazine.size(); i++)
	{
		s.insert(magazine[i]);
	}
	for (int i = 0; i < ransomNote.size(); i++)
	{
		it = s.find(ransomNote[i]);
		if (it == s.end())
		{
			return false;
		}
		else
		{
			s.erase(s.lower_bound(ransomNote[i]));
		}
	}
	return true;
}
bool canConstruct2(string ransomNote, string magazine)
{
	vector<int> data(26);
	for (int i = 0; i < magazine.size(); i++)
	{
		data[magazine[i] - 'a']++;
	}
	for (int i = 0; i < ransomNote.size(); i++)

	{
		data[ransomNote[i] - 'a']--;
		if (data[ransomNote[i] - 'a'] < 0)
		{
			return false;
		}
	}
	return true;
}