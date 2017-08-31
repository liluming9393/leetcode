//You are a product manager and currently leading a team to develop a new product.Unfortunately, the latest version of your product fails the quality check.Since each version is developed based on the previous version, all the versions after a bad version are also bad.
//Suppose you have n versions[1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
//You are given an API bool isBadVersion(version) which will return whether version is bad.Implement a function to find the first bad version.You should minimize the number of calls to the API.
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
int firstBadVersion(int n);
bool isBadVersion(int version);
int main()
{
	int n;
	while (cin >> n)
	{
		int result = firstBadVersion(n);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
bool isBadVersion(int version)
{
	int badversion = 5;
	if (version < badversion)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int firstBadVersion(int n)
{
	if (isBadVersion(1) == true)
	{
		return 1;
	}
	int low = 2;
	int high = n;
	int mid;
	while (low <= high)
	{
		if (isBadVersion(low) == true && isBadVersion(low - 1) == false)
		{
			return low;
		}
		if (isBadVersion(high) == true && isBadVersion(high - 1) == false)
		{
			return high;
		}
		mid = low + (high - low) / 2;
		if (isBadVersion(mid) == true && isBadVersion(mid - 1) == false)
		{
			return mid;
		}
		else if (isBadVersion(mid) == true && isBadVersion(mid - 1) == true)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}