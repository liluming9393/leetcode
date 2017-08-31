/*Given an integer, write an algorithm to convert it to hexadecimal.For negative integer, two¡¯s complement method is used.
Note:
All letters in hexadecimal(a - f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32 - bit signed integer.
You must not use any method provided by the library which converts / formats the number to hex directly.
Example 1:
Input :
	26
Output :
	"1a"
Example 2 :
Input :
	 -1
Output :
	"ffffffff"*/
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
string toHex(int num);
int main()
{
	int num;
	while (cin >> num)
	{
		string result = toHex(num);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
string toHex(int num)
{
	if (num == 0)
	{
		return "0";
	}
	string result;
	uint32_t data = num;
	while (data != 0)
	{
		int temp = data % 16;
		if (temp < 10)
		{
			result = result + (char)(temp + '0');
		}
		else
		{
			result = result + (char)(temp - 10 + 'a');
		}
		data /= 16;
	}
	reverse(result.begin(), result.end());
	return result;
}