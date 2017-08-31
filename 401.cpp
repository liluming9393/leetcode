/*A binary watch has 4 LEDs on the top which represent the hours(0 - 11), and the 6 LEDs on the bottom represent the minutes(0 - 59).
Each LED represents a zero or one, with the least significant bit on the right.
For example, the above binary watch reads "3:25".
Given a non - negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
Example:
Input : n = 1
Return : ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note :
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".*/
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
vector<string> readBinaryWatch(int num);
void Perm(vector<int> &data, int i, int k, int num, vector<string> &result);
int main()
{
	int num;
	while (cin >> num)
	{
		vector<string> result = readBinaryWatch(num);
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
vector<string> readBinaryWatch(int num)
{
	vector<string> result;
	vector<int> data;
	data.resize(10);
	Perm(data, 0, 0, num, result);
	return result;
}
void Perm(vector<int> &data, int i, int k, int num, vector<string> &result)
{
	if (k == num)
	{
		int hour = 0;
		int minute = 0;
		for (int i = 0; i < 4; i++)
		{
			hour = hour * 2 + data[i];
		}
		for (int i = 4; i < 10; i++)
		{
			minute = minute * 2 + data[i];
		}
		if (hour < 12 && minute < 60)
		{
			string temp;
			if (hour < 10)
			{
				temp = temp + (char)(hour + '0');
			}
			else
			{
				temp = temp + (char)(hour / 10 + '0') + (char)(hour % 10 + '0');
			}
			temp = temp + ":";
			if (minute < 10)
			{
				temp = temp +"0" + (char)(minute + '0');
			}
			else
			{
				temp = temp + (char)(minute / 10 + '0') + (char)(minute % 10 + '0');
			}
			result.push_back(temp);
		}
		return;
	}
	if (i == 10)
	{
		return;
	}
	data[i] = 1;
	Perm(data, i + 1, k + 1, num, result);
	data[i] = 0;
	Perm(data, i + 1, k, num, result);
}