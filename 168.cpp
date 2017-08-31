//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
string convertToTitle(int n);
int main()
{
	int n =702;
	string s = convertToTitle(n);
	cout << s << endl;
	system("pause");
	return 0;
}
string convertToTitle(int n)
{
	string s;
	string s1;
	while (n > 0)
	{
		if (n % 26 != 0)
		{
			s1 = n % 26 + 64;
			s = s1 + s;
			n = n / 26;
		}
		else
		{
			s1 = "Z";
			s = s1 + s;
			n = n / 26 - 1;
		}	
	}
	return s;
}