/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line : "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows :

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".*/
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
string convert(string s, int numRows);
int main()
{
	//string s = "PAYPALISHIRING";
	string s = "AB";
	int numRows = 1;
	string result = convert(s, numRows);
	cout << result << endl;
	system("pause");
	return 0;
}
string convert(string s, int numRows)
{
	vector<vector<char>> data(numRows);
	int j = 0;
	int flag = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (j == 0)
		{
			flag = 0;
		}
		else if (j == numRows - 1)
		{
			flag = 1;
		}
		data[j].push_back(s[i]);
		if (flag == 0 && numRows != 1)
		{
			j++;
		}
		else if (flag == 1 && numRows != 1)
		{
			j--;
		}
	}
	string result;
	for (int m = 0; m < numRows; m++)
	{
		for (int n = 0; n < data[m].size(); n++)
		{
			result += data[m][n];
		}
	}
	return result;
}