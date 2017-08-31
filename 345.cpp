/*Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2 :
Given s = "leetcode", return "leotcede".

Note :
	 The vowels does not include the letter "y".*/
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
string reverseVowels(string s);
int main()
{
	while (1)
	{
		string s;
		cin >> s;
		string result = reverseVowels(s);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
string reverseVowels(string s)
{
	int i = 0;
	int j = s.size() - 1;
	while (i < j)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
		{
			if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')
			{
				swap(s[i], s[j]);
				i++;
				j--;
			}
			else
			{
				j--;
			}
		}
		else
		{
			i++;
			if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')
			{
				
			}
			else
			{
				j--;
			}
		}
	}
	return s;
}