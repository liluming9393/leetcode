/*Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non - space characters.
Please note that the string does not contain any non - printable characters.
Example:
Input : "Hello, my name is John"
Output : 5*/
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int countSegments(string s);
int main()
{
	string s;
	while (1)
	{
		getline(cin, s);
		int result = countSegments(s);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
int countSegments(string s) 
{
	int result = 0;
	int flag = 0;
	if (s.size() == 0)
	{
		return 0;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ' && flag == 1)
		{
			flag = 0;
		}
		else if (s[i] != ' ' && flag == 0)
		{
			flag = 1;
			result++;
		}
	}
	return result;
}