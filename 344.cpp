//Write a function that takes a string as input and returns the string reversed.
//Example:Given s = "hello", return "olleh".
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
string reverseString(string s);
int main()
{
	string s = "hello";
	string result = reverseString(s);
	cout << result << endl;
	system("pause");
	return 0;
}
string reverseString(string s)
{
	 reverse(s.begin(), s.end());
	 return s;
}