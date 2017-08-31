//Given a roman numeral, convert it to an integer.
//Input is guaranteed to be within the range from 1 to 3999.
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int romanToInt(string s);
int main()
{
	while (1)
	{
		string s;
		cin >> s;
		int result = romanToInt(s);
		cout << result << endl;
	}
	
	system("pause");
	return 0;
}
//从右往左扫描字符串，如果右边的数比左边小则加上，如果右边的数比左边大如IV，则减去左边的数
int romanToInt(string s) 
{
	int result = 0;
	int temp1 = 0;
	int temp2 = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == 'I')
			temp2 = 1;
		else if (s[i] == 'V')
			temp2 = 5;
		else if (s[i] == 'X')
			temp2 = 10;
		else if (s[i] == 'L')
			temp2 = 50;
		else if (s[i] == 'C')
			temp2 = 100;
		else if (s[i] == 'D')
			temp2 = 500;
		else if (s[i] == 'M')
			temp2 = 1000;
		if (temp2 >= temp1)
		{
			result += temp2;
		}
		else
		{
			result -= temp2;
		}
		temp1 = temp2;
	}
	return result;
}