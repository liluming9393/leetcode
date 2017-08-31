//Write a program to check whether a given number is an ugly number.
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
//Note that 1 is typically treated as an ugly number.
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
bool isUgly1(int num);
bool isUgly2(int num);
bool isprime(int n);
int main()
{
	int n;
	while (cin >> n)
	{
		bool result = isUgly2(n);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
bool isprime(int n)
{
	if (n == 2)
	{
		return true;
	}
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}
bool isUgly1(int num)
{
	if (num < 0)
		return false;
	for (int i = 2; i <= num; i++)
	{
		if (num / i*i == num)
		{
			if (isprime(i) == true)
			{
				if (i != 2 && i != 3 && i != 5)
				{
					return false;
				}
			}
		}
	}
	return true;
}
bool isUgly2(int num)
{
	if (num <= 0)
		return false;
	if (num == 1)
		return true;
	while (num % 2 == 0)
		num /= 2;
	while (num % 3 == 0)
		num /= 3;
	while (num % 5 == 0)
		num /= 5;
	if (num == 1)
		return true;
	return false;
}