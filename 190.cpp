//Reverse bits of a given 32 bits unsigned integer.
//For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
uint32_t reverseBits(uint32_t n);
int main()
{
	uint32_t n;
	cin >> n;
	uint32_t result = reverseBits(n);
	cout << result << endl;
	system("pause");
	return 0;
}
uint32_t reverseBits(uint32_t n)
{
	uint32_t result = 0;
	for (int i = 0; i < 32; i++)
	{
		if (n & 1 == 1)
		{
			result = result << 1;
			result |= 1;
			n = n >> 1;
		}
		else
		{
			result = result << 1;
			n = n >> 1;
		}
	}
	return result;
}