/*Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
Note:
n is positive and will fit within the range of a 32 - bit signed integer(n < 231).
Example 1 :
Input :
	3
Output :
	3
Example 2 :
Input :
	11
Output :
	0
Explanation :The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.*/
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
int findNthDigit1(int n);
int findNthDigit2(int n);
int main()
{
	int n;
	while (cin >> n)
	{
		int result = findNthDigit2(n);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
int findNthDigit1(int n)
{
	stack<int> data;
	int num = 1;
	int count = 0;
	int result;
	while (1)
	{
		int temp = num;
		while (num != 0)
		{
			data.push(num % 10);
			num = num / 10;
		}
		while (data.empty() == 0)
		{
			result = data.top();
			data.pop();
			count++;
			if (count == n)
			{
				return result;
			}
		}
		num = temp + 1;
	}
	return 0;
}
int findNthDigit2(int n)
{
	if (n < 10)
		return n;
	int digits = 1;//位数
	long long int num = 9;//该位数下的数字个数
	while (n > digits*num)
	{
		n = n - digits*num;
		digits++;
		num *= 10;
	}
	num /= 10;
	long long int key = num + num / 9 + (n - 1) / digits;
	stack<int> data;
	while (key != 0)
	{
		data.push(key % 10);
		key /= 10;
	}
	for (int i = 0; i < (n - 1) % digits; i++)
	{
		data.pop();
	}
	return data.top();
}