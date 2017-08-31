//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
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
bool isValid(string s);
int main()
{
	while (1)
	{
		string s;
		cin >> s;
		bool result = isValid(s);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
bool isValid(string s)
{
	stack<char> data;
	int i = s.size() - 1;
	while (i >= 0)
	{
		if (s[i] == ']' || s[i] == '}' || s[i] == ')')
		{
			data.push(s[i]);
			i--;
		}
		else
		{
			if (data.empty())
			{
				return false;
			}
			else
			{
				char temp = data.top();
				if ((temp == ']' && s[i] != '[') || (temp == '}' && s[i] != '{') || (temp == ')' && s[i] != '('))
				{
					return false;
				}
				else
				{
					data.pop();
					i--;
				}
			}
		}
	}
	if (!data.empty())
	{
		return false;
	}
	return true;
}