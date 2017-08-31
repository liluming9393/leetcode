/*Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.
Note:
Assume the length of given string will not exceed 1, 010.
Example :
Input :
	"abccccdd"
Output :
	7
Explanation :
	One longest palindrome that can be built is "dccaccd", whose length is 7.*/
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
int longestPalindrome(string s);
int main()
{
	while (1)
	{
		string s;
		getline(cin, s);
		int result = longestPalindrome(s);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
int longestPalindrome(string s)
{
	vector<int>temp(52);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a'&&s[i] <= 'z')
		{
			temp[s[i] - 'a']++;
		}
		else if (s[i] >= 'A'&&s[i] <= 'Z')
		{
			temp[s[i] - 'A' + 26]++;
		}
	}
	int result = 0;
	for (int i = 0; i < 52; i++)
	{
		result += temp[i] / 2 * 2;
	}
	if (result < s.size())
	{
		result++;
	}
	return result;
}