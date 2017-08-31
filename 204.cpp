//Count the number of prime numbers less than a non - negative number, n.
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
int countPrimes1(int n);
int countPrimes2(int n);
bool isPrime(int n);
int main()
{
	int n;
	while (cin >> n)
	{
		int result = countPrimes2(n);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
bool isPrime(int n)
{
	if (n == 2)
		return true;
	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}
int countPrimes1(int n)
{
	int result = 0;
	for (int i = 2; i < n; i++)
	{
		if (isPrime(i) == true)
		{
			result++;
		}
	}
	return result;
}
int countPrimes2(int n)
{
	int result = 0;
	vector<int> flag(n + 1);
	for (int i = 2; i < n; i++)
	{
		if (flag[i] == 0)
		{
			result++;
			for (int j = 1; j <= n / i; j++)
			{
				flag[i*j] = 1;
			}
		}
	}
	return result;
}