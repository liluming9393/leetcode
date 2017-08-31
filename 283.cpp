//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be[1, 3, 12, 0, 0].
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
void moveZeroes1(vector<int>& nums);
void moveZeroes2(vector<int>& nums);

int main()
{
	int data[5] = { 0, 0, 1, 0, 2 };
	vector<int> nums(data, data + 5);
	moveZeroes2(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
void moveZeroes1(vector<int>& nums)
{
	int i = 0;
	int j = 0;
	for (i = 0, j = 1; i < nums.size() - 1, j < nums.size();)
	{
		if (nums[i] == 0 && nums[j] != 0)
		{
			swap(nums[i], nums[j]);
			i++;
			j++;
		}
		else if (nums[i] == 0 && nums[j] == 0)
		{
			j++;
		}
		else if (nums[i] != 0 && nums[j] == 0)
		{
			i++;
			j++;
		}
		else if (nums[i] != 0 && nums[j] != 0)
		{
			i = i + 2;
			j = j + 2;
		}
	}
}
void moveZeroes2(vector<int>& nums)
{
	int i = 0;
	int j = 0;
	for (i = 0, j = 1; i < nums.size() - 1, j < nums.size();)
	{
		if (nums[i] == 0)
		{
			if (nums[j] != 0)
			{
				swap(nums[i], nums[j]);
				i++;
				j++;
			}
			else
			{
				j++;
			}
		}		else
		{
			if (nums[j] == 0)
			{
				i++;
				j++;
			}
			else
			{
				i = i + 2;
				j = j + 2;
			}
		}
	}
}
