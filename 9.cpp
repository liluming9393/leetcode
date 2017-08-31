/*Determine whether an integer is a palindrome.Do this without extra space.
Some hints :
Could negative integers be palindromes ? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer.However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow.How would you handle such case ?
There is a more generic way of solving this problem.*/
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
bool isPalindrome1(int x);
bool isPalindrome2(int x);
int main()
{
	cout << INT_MAX << endl;
	int x;
	while (cin >> x)
	{
		bool result = isPalindrome2(x);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
bool isPalindrome1(int x)
{
	if (x < 0)
		return false;
	long long int temp = 0;
	int num = x;
	while (x != 0)
	{
		temp = temp * 10 + x % 10;
		x /= 10;
	}
	if (temp != num)
		return false;
	return true;
}
bool isPalindrome2(int x)
{
	if (x < 0)
		return false;
	int left;
	int right;
	int div = 1;
	int num = x;
	while (x >= 10)
	{
		div = div * 10;
		x = x / 10;
	}
	x = num;
	while (x != 0)
	{
		left = x / div;
		right = x % 10;
		if (left != right)
			return false;
		x = x - left*div;
		x = x / 10;
		div = div / 100;
	}
	return true;
}