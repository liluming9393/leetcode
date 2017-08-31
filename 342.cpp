//Given an integer(signed 32 bits), write a function to check whether it is a power of 4.
//Example:Given num = 16, return true.Given num = 5, return false.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
bool isPowerOfFour1(int num);
bool isPowerOfFour2(int num);
bool isPowerOfFour3(int num);
int main()
{
	int num = 16;
	bool result = isPowerOfFour2(num);
	cout << result << endl;
	system("pause");
	return 0;
}
bool isPowerOfFour1(int num)
{
	if (num == 0)
		return false;
	else if (num == 1)
		return true;
	while (num % 4 == 0)
	{
		num = num / 4;
		if (num == 1)
			return true;
	}
	return false;
}
bool isPowerOfFour2(int num)
{
	return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
}
bool isPowerOfFour3(int num)
{
	return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
}
