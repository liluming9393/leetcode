//Related to question Excel Sheet Column Title
//Given a column title as appear in an Excel sheet, return its corresponding column number.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int titleToNumber(string s);
int main()
{
	string s = "AB";
	int result = titleToNumber(s);
	cout << result << endl;
	system("pause");
	return 0;
}
int titleToNumber(string s)
{
	int result = 0;
	for (int i = 0; i < s.size(); i++)
	{
		result = result * 26 + s[i] - 64;
	}
	return result;
}