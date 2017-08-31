//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//Do not allocate extra space for another array, you must do this in place with constant memory.
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int removeDuplicates(vector<int>& nums);
int main()
{
	int num[] = { 1, 1, 2, 3, 4, 4 };
	vector<int> nums(num, num + 6);
	int result = removeDuplicates(nums);
	cout << result << endl;
	system("pause");
	return 0;
}
int removeDuplicates(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	int result = 1;
	int temp = nums[0];
	int j = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		if (temp != nums[i])
		{
			result++;
			temp = nums[i];
			nums[j] = nums[i];
			j++;
		}
	}
	return result;
}