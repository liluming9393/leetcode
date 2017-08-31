/*Given a non - empty array of integers, return the third maximum number in this array.If it does not exist, return the maximum number.The time complexity must be in O(n).
Example 1:
Input : [3, 2, 1]
Output : 1
Explanation : The third maximum is 1.
Example 2 :
Input : [1, 2]
Output : 2
Explanation : The third maximum does not exist, so the maximum(2) is returned instead.
Example 3 :
Input : [2, 2, 3, 1]
Output : 1
Explanation : Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.*/
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int thirdMax(vector<int>& nums);
int main()
{
	vector<int> nums = { 2, 2, 1 };
	int result = thirdMax(nums);
	cout << result << endl;
	system("pause");
	return 0;
}
int thirdMax(vector<int>& nums) 
{
	int result;
	if (nums.size() == 1)
	{
		result = nums[0];
		return result;
	}
	else if (nums.size() == 2)
	{
		if (nums[0] >= nums[1])
		{
			result = nums[0];
		}
		else
		{
			result = nums[1];
		}
		return result;
	}
	int flag = 1;
	int max1 = nums[0];
	int max2;
	int max3;
	for (int i = 1; i < nums.size(); i++)
	{
		if (flag == 1)
		{
			if (nums[i] > max1)
			{
				max2 = max1;
				max1 = nums[i];
				flag = 2;
			}
			else if (nums[i] < max1)
			{
				max2 = nums[i];
				flag = 2;
			}
		}
		else if (flag == 2)
		{
			if (nums[i] > max1)
			{
				max3 = max2;
				max2 = max1;
				max1 = nums[i];
				flag = 3;
			}
			else if (nums[i] < max1 && nums[i] > max2)
			{
				max3 = max2;
				max2 = nums[i];
				flag = 3;
			}
			else if (nums[i] < max2)
			{
				max3 = nums[i];
				flag = 3;
			}
		}
		else if (flag == 3)
		{
			if (nums[i] > max1)
			{
				max3 = max2;
				max2 = max1;
				max1 = nums[i];
			}
			else if (nums[i] < max1 && nums[i] > max2)
			{
				max3 = max2;
				max2 = nums[i];
			}
			else if (nums[i] < max2 && nums[i] > max3)
			{
				max3 = nums[i];
			}
		}
	}
	if (flag != 3)
	{
		return max1;
	}
	return max3;
}