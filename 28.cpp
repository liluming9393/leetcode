//Implement strStr().
//Returns the index of the first occurrence of needle in haystack, or - 1 if needle is not part of haystack.
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
int strStr(string haystack, string needle);
int main()
{
	while (1)
	{
		string haystack;
		cin >> haystack;
		string needle;
		cin >> needle;
		int result = strStr(haystack, needle);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
int strStr(string haystack, string needle)
{
	if (haystack.size() < needle.size())
	{
		return -1;
	}
	for (int i = 0; i < haystack.size() - needle.size() + 1; i++)
	{
		if (haystack.substr(i, needle.size()) == needle)
		{
			return i;
		}
	}
	return -1;
}