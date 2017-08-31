/*We are playing the Guess Game.The game is as follows :

I pick a number from 1 to n.You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre - defined API guess(int num) which returns 3 possible results(-1, 1, or 0) :

-1 : My number is lower
1 : My number is higher
0 : Congrats!You got it!
Example :
		n = 10, I pick 6.

		Return 6.*/
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
int guessNumber(int n);
int guess(int num);
int main()
{
	int n;
	while (cin >> n)
	{
		int result = guessNumber(n);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
int guess(int num)
{
	int data = 12;
	if (num == data)
	{
		return 0;
	}
	else if (num > data)
	{
		return -1;
	}
	else if (num < data)
	{
		return 1;
	}
}
int guessNumber(int n)
{
	int low = 1;
	int high = n;
	int mid;
	while (low <= high)
	{
		if (guess(low) == 0)
		{
			return low;
		}
		if (guess(high) == 0)
		{
			return high;
		}
		mid = low + (high - low) / 2;
		if (guess(mid) == 0)
		{
			return mid;
		}
		else if (guess(mid) == 1)
		{
			low = mid + 1;
		}
		else if (guess(mid) == -1)
		{
			high = mid - 1;
		}
	}
	if (low > high)
	{
		return -1;
	}
	return -1;
}