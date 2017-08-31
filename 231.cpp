//Given an integer, write a function to determine if it is a power of two.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
bool isPowerOfTwo(int n);
int main()
{
	int n = 0;
	bool result = isPowerOfTwo(n);
	cout << result << endl;
	system("pause");
	return 0;
}
bool isPowerOfTwo(int n)
{
	return (n > 0) && (!(n & (n - 1)));
}