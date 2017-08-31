/*Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non - empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes :
	  You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.*/
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
bool wordPattern(string pattern, string str);
int main()
{
	while (1)
	{
		string pattern;
		getline(cin, pattern);
		string str;
		getline(cin, str);
		bool result = wordPattern(pattern, str);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
bool wordPattern(string pattern, string str)
{
	vector<string> data;
	int last_pos = 0;
	int pos = 0;
	bool result = true;
	while (1)
	{
		pos = str.find_first_of(" ", last_pos);
		if (pos != string::npos)
		{
			data.push_back(str.substr(last_pos, pos - last_pos));
			last_pos = pos + 1;
		}
		else
		{
			data.push_back(str.substr(last_pos, str.size() - last_pos));
			break;
		}
	}
	if (pattern.size() != data.size())
	{
		return false;
	}
	map<char, string> m;
	map<char, string>::iterator it;
	for (int i = 0; i < pattern.size(); i++)
	{
		it = m.find(pattern[i]);
		if (it == m.end())
		{
			m.insert(pair<char, string>(pattern[i], data[i]));
		}
		else
		{
			if (it->second != data[i])
			{
				return false;
			}
		}
	}
	map<string, char>n;
	map<string, char>::iterator it1;
	for (int i = 0; i < pattern.size(); i++)
	{
		it1 = n.find(data[i]);
		if (it1 == n.end())
		{
			n.insert(pair<string, char>(data[i], pattern[i]));
		}
		else
		{
			if (it1->second != pattern[i])
			{
				return false;
			}
		}
	}
	return result;
}