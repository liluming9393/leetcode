//Write a function that takes an unsigned integer and returns the number of ¡¯1' bits it has (also known as the Hamming weight).
//For example, the 32 - bit integer ¡¯11' has binary representation 00000000000000000000000000001011, so the function should return 3.
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int hammingWeight1(uint32_t n);
int hammingWeight2(uint32_t n);
int main()
{
	int num = 11;
	int result = hammingWeight2(num);
	cout << result << endl;
	system("pause");
	return 0;
}
int hammingWeight1(uint32_t n) 
{
	int result = 0;
	for (int i = 0; i < 32; i++)
	{
		if (n & 1 == 1)
		{
			result++;
		}
		n = n >> 1;
	}
	return result;
}
int hammingWeight2(uint32_t n)
{
	int result = 0;
	while (n) {
		result++;
		n = n&(n - 1);
	}
	return result;
}