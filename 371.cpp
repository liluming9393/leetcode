//Calculate the sum of two integers a and b, but you are not allowed to use the operator + and - .
//Example:Given a = 1 and b = 2, return 3.
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int getSum1(int a, int b);
int main()
{
	int a;
	cin >> a;
	int b;
	cin >> b;
	int result = getSum1(a, b);
	cout << result << endl;
	system("pause");
	return 0;
}
int getSum1(int a, int b) 
{
	while (b != 0)
	{
		int c = a&b;
		c = c << 1;
		a = a^b;
		b = c;
	}
	return a;
}