/*Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed.It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3, 2, 2, 3], val = 3*/
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int removeElement1(vector<int>& nums, int val);
int removeElement2(vector<int>& nums, int val);
int main()
{
	vector<int> nums = { 3, 3, 2, 2 };
	int val = 3;
	int result = removeElement2(nums, val);
	cout << result << endl;
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
int removeElement1(vector<int>& nums, int val) 
{
	int result = nums.size();
	vector<int>::iterator it;
	for (it = nums.begin(); it != nums.end();)
	{
		if (*it == val)
		{
			nums.erase(it);
			it = nums.begin();
			result -= 1;
		}
		else
		{
			it++;
		}
	}
	return result;
}
int removeElement2(vector<int>& nums, int val)
{
	multiset<int> num;
	multiset<int>::iterator it;
	for (int i = 0; i < nums.size(); i++)
	{
		num.insert(nums[i]);
	}
	num.erase(val);
	nums.clear();
	for (it = num.begin(); it != num.end(); it++)
	{
		nums.push_back(*it);
	}
	return nums.size();
}