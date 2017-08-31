//Given an integer n, return the number of trailing zeroes in n!.
//Note: Your solution should be in logarithmic time complexity.
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
int trailingZeroes(int n);
int main()
{
	int n;
	while (cin >> n)
	{
		int result = trailingZeroes(n);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
int trailingZeroes(int n)
{
	int result = 0;
	while (n > 0)
	{
		result += n / 5;
		n = n / 5;
	}
	return result;
}