//Given a non - negative number represented as an array of digits, plus one to the number.
//The digits are stored such that the most significant digit is at the head of the list.
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
vector<int> plusOne(vector<int>& digits);
int main()
{
	vector<int> digits = { 9, 9 };
	vector<int> result = plusOne(digits);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
vector<int> plusOne(vector<int>& digits) 
{
	vector<int> result;
	int carry = 0;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (i == digits.size() - 1)
		{
			digits[i] += 1 + carry;
		}
		else
		{
			digits[i] += carry;
		}
		if (digits[i] == 10)
		{
			carry = 1;
			digits[i] = 0;
		}
		else
		{
			carry = 0;
			break;
		}
	}
	if (carry == 0)
	{
		return digits;
	}
	else
	{
		result.push_back(1);
		for (int i = 0; i < digits.size(); i++)
		{
			result.push_back(digits[i]);
		}
	}
	return result;
}