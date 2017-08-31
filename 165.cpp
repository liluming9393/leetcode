/*Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non - empty and contain only digits and the.character.
The.character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second - level revision of the second first - level revision.

Here is an example of version numbers ordering :

0.1 < 1.1 < 1.2 < 13.37*/
#include<iostream>
#include<stdint.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int compareVersion(string version1, string version2);
int main()
{
	while (1)
	{
		string version1;
		getline(cin, version1);
		string version2;
		getline(cin, version2);
		int result = compareVersion(version1, version2);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
int compareVersion(string version1, string version2)
{
	vector<int> v1;
	vector<int> v2;
	int last_pos = 0;
	int pos = 0;
	while (pos != string::npos)
	{
		pos = version1.find('.', last_pos);
		v1.push_back(atoi(version1.substr(last_pos, pos - last_pos).c_str()));
		last_pos = pos + 1;
	}
	last_pos = 0;
	pos = 0;
	while (pos != string::npos)
	{
		pos = version2.find('.', last_pos);
		v2.push_back(atoi(version2.substr(last_pos, pos - last_pos).c_str()));
		last_pos = pos + 1;
	}
	int len1 = v1.size();
	int len2 = v2.size();
	if (len1 < len2)
	{
		for (int i = 0; i < len2 - len1; i++)
		{
			v1.push_back(0);
		}
	}
	else if (len1 > len2)
	{
		for (int i = 0; i < len1 - len2; i++)
		{
			v2.push_back(0);
		}
	}
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i] > v2[i])
		{
			return 1;
		}
		else if (v1[i] < v2[i])
		{
			return -1;
		}
	}
	return 0;
}