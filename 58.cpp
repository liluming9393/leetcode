/*Given a string s consists of upper / lower - case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non - space characters only.

	  For example,
	  Given s = "Hello World",
	  return 5.*/
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int lengthOfLastWord(string s);
int main()
{
	while (1)
	{
		string s;
		getline(cin, s);
		int result = lengthOfLastWord(s);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
int lengthOfLastWord(string s) 
{
	int result = 0;
	int flag = 0;
	if (s.length() == 0)
	{
		return 0;
	}
	else 
	{
		for (int i = s.length() - 1; i >= 0; i--)
		{
			if (s[i] != ' ')
			{
				flag = 1;
				result++;
			}
			else if (s[i] == ' ' && flag == 1)
			{
				break;
			}
		}
	}
	return result;
}