/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty ? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.*/
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
bool isPalindrome(string s);
int main()
{
	while (1)
	{
		string s;
		getline(cin, s);
		bool result = isPalindrome(s);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
bool isPalindrome(string s)
{
	vector<int> v;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			v.push_back(s[i] - 'a');
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			v.push_back(s[i] - 'A');
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			v.push_back(s[i] - '0' + 100);
		}
	}
	if (v.size() == 0)
	{
		return true;
	}
	else
	{
		int i = 0;
		int j = v.size() - 1;
		while (i < j)
		{
			if (v[i] != v[j])
			{
				return false;
			}
			else
			{
				i++;
				j--;
			}
		}
	}
	return true;
}