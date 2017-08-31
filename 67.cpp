//Given two binary strings, return their sum(also a binary string).
//For example,
//a = "11"
//b = "1"
//Return "100".
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
string addBinary(string a, string b);
int main()
{
	string a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
	string b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
	//"110111101100010011000101110110100000011101000101011001000011011000001100011110011010010011000000000"
	string result = addBinary(a, b);
	cout << result << endl;
	system("pause");
	return 0;
}
string addBinary(string a, string b)
{
	string result;
	if (a.size() < b.size())
	{
		swap(a, b);
	}
	int carry = 0;
	int j;
	for (int i = b.size() - 1, j = a.size() - 1; i >= 0; i-- , j--)
	{
		int sum = a[j] - '0' + b[i] - '0' + carry;
		if (sum == 0)
		{
			result = '0' + result;
			carry = 0;
		}
		else if (sum == 1)
		{
			result = '1' + result;
			carry = 0;
		}
		else if (sum == 2)
		{
			result = '0' + result;
			carry = 1;
		}
		else if (sum == 3)
		{
			result = '1' + result;
			carry = 1;
		}
	}
	for (j = a.size() - 1 - b.size(); j >= 0; j--)
	{
		int sum = a[j] - '0' + carry;
		if (sum == 0)
		{
			result = '0' + result;
			carry = 0;
		}
		else if (sum == 1)
		{
			result = '1' + result;
			carry = 0;
		}
		else if (sum == 2)
		{
			result = '0' + result;
			carry = 1;
		}
	}
	if (carry == 1)
	{
		result = '1' + result;
	}
	return result;
}