/*Reverse digits of an integer.
Example1 : x = 123, return 321
Example2 : x = -123, return -321
Have you thought about this ?
Here are some good questions to ask before coding.Bonus points for you if you have already thought through this!
If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow ? Assume the input is a 32 - bit integer, then the reverse of 1000000003 overflows.How should you handle such cases ?
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.*/
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
int reverse1(int x);
int reverse2(int x);
int main()
{
	int x;
	while (cin >> x)
	{
		int result = reverse2(x);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
int reverse1(int x)
{
	long long int result = 0;
	queue<int> data;
	while (x != 0)
	{
		data.push(x % 10);
		x /= 10;
	}
	while (data.empty() == 0)
	{
		result = result * 10 + data.front();
		data.pop();
	}
	if (x < 0)
	{
		result = -result;
	}
	if (result > INT_MAX)
		return 0;
	if (result < INT_MIN)
		return 0;
	return result;
}
int reverse2(int x)
{
	long long int result = 0;
	while (x != 0)
	{
		result = result * 10 + x % 10;
		x /= 10;
	}
	if (x < 0)
	{
		result = -result;
	}
	if (result > INT_MAX)
		return 0;
	if (result < INT_MIN)
		return 0;
	return result;
}