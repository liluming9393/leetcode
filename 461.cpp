/*The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
Note:
0 ¡Ü x, y < 231.
Example :
Input : x = 1, y = 4
Output : 2
Explanation :
1   (0 0 0 1)
4   (0 1 0 0)
       ¡ü   ¡ü
The above arrows point to positions where the corresponding bits are different.*/
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int hammingDistance(int x, int y);
int main()
{
	int x, y, result;
	x = 1;
	y = 4;
	result = hammingDistance(x, y);
	cout << result << endl;
	system("pause");
	return 0;
}
int hammingDistance(int x, int y) 
{
	int result = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((x & 1) != (y & 1))
		{
			result++;
		}
		x =  x >> 1;
		y =  y >> 1;
	}
	return result;
}