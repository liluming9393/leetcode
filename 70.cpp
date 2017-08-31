//You are climbing a stair case.It takes n steps to reach to the top.
//Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int climbStairs1(int n);
int climbStairs2(int n);

int main()
{
	int n = 7;
	int result = climbStairs2(n);
	cout << result << endl;
	system("pause");
	return 0;
}
int climbStairs1(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return climbStairs1(n - 1) + climbStairs1(n - 2);
}
int climbStairs2(int n)
{
	int data[3];
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	data[0] = 1;
	data[1] = 2;
	int i;
	for (i = 2; i < n; i++)
	{
		data[i % 3] = data[(i - 1) % 3] + data[(i - 2) % 3];
	}
	return data[(i - 1) % 3];
}
