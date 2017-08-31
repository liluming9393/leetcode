//You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones.The one who removes the last stone will be the winner.You will take the first turn to remove the stones.
//Both of you are very clever and have optimal strategies for the game.Write a function to determine whether you can win the game given the number of stones in the heap.
//For example, if there are 4 stones in the heap, then you will never win the game : no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
bool canWinNim1(int n);
bool canWinNim2(int n);
int main()
{
	int num;
	cin >> num;
	bool result = canWinNim2(num);
	cout << result << endl;

	system("pause");
	return 0;
}
bool canWinNim1(int n) //递归算法复杂度高，超时
{
	bool result1;
	bool result2;
	bool result3;
	if (n >= 1 && n <= 3)
	{
		return true;
	}
	else if (n >= 4)
	{
		for (int i = 1; i <= 3; i++)
		{
			result1 = canWinNim1(n - 1);
			result2 = canWinNim1(n - 2);
			result3 = canWinNim1(n - 3);
		}
		if (result1 == false || result2 == false || result3 == false)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool canWinNim2(int n)
{
	return (n % 4 != 0);
}