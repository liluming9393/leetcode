//Given an integer, write a function to determine if it is a power of three.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
bool isPowerOfThree1(int n);
bool isPowerOfThree2(int n);
bool isPowerOfThree3(int n);

int main()
{
	int num = 243;
	bool result = isPowerOfThree3(num);
	cout << result << endl;
	system("pause");
	return 0;
}
bool isPowerOfThree1(int n)
{
	if (n == 0)
		return false;
	else if (n == 1)
		return true;
	while (n % 3 == 0)
	{
		n = n / 3;
		if (n == 1)
			return true;
	}
	return false;
}
bool isPowerOfThree2(int n)
{
	if (n == 0)
		return false;
	double res = log(n) / log(3);
	return abs(res - round(res)) < 0.000000000001;
}
bool isPowerOfThree3(int n)
{
	return (n > 0 && 1162261467 % n == 0);
}