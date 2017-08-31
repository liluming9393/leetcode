/*Given two non - negative numbers num1 and num2 represented as string, return the sum of num1 and num2.
Note:

The length of both num1 and num2 is < 5100.
	Both num1 and num2 contains only digits 0 - 9.
	Both num1 and num2 does not contain any leading zero.
	You must not use any built - in BigInteger library or convert the inputs to integer directly.*/
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
string addStrings(string num1, string num2);
int main()
{
	while (1)
	{
		string num1;
		getline(cin, num1);
		string num2;
		getline(cin, num2);
		string result;
		result = addStrings(num1, num2);
		cout << result << endl;
	}

	system("pause");
	return 0;
}
string addStrings(string num1, string num2)
{
	string result;
	if (num1.size() < num2.size())
	{
		swap(num1, num2);
	}
	int carry = 0;
	int j = num1.size() - 1;
	for (int i = num2.size() - 1; i >= 0; i--)
	{
		int temp = num1[j] - '0' + num2[i] - '0' + carry;
		j--;
		if (temp < 10)
		{
			carry = 0;
			result = (char)(temp + '0') + result;
		}
		else
		{
			carry = 1;
			result = (char)(temp - 10 +'0') + result;
		}
	}
	for (int i = j; i >= 0; i--)
	{
		int temp = num1[i] - '0' + carry;
		if (temp < 10)
		{
			carry = 0;
			result = (char)(temp + '0') + result;
		}
		else
		{
			carry = 1;
			result = (char)(temp - 10 + '0') + result;
		}
	}
	if (carry == 1)
	{
		result = '1' + result;
	}
	return result;
}