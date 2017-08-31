//Given a non - negative integer num, repeatedly add all its digits until the result has only one digit.
//For example :Given num = 38, the process is like : 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int addDigits1(int num);
int addDigits2(int num);
int main()
{
	int num;
	cin >> num;
	int result = addDigits2(num);
	cout << result << endl;
	system("pause");
	return 0;
}
int addDigits1(int num) 
{
	int result = 0;
	if (num == 0)
	{
		return 0;
	}
	else
	{
		while (1)
		{
			while (num != 0)
			{
				result += num % 10;
				num = num / 10;
			}
			if (result < 10)
			{
				return result;
			}
			else
			{
				num = result;
				result = 0;
			}
		}
	}
	return 0;
}
int addDigits2(int num)
{
	return (num - 1) % 9 + 1;
}