//You are a professional robber planning to rob houses along a street.
//Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//Given a list of non - negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
#include<iostream>
#include<stdint.h>
#include<vector>
#include<deque>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
using namespace std;
int rob(vector<int>& nums);
int main()
{
	vector<int> nums = { 1, 2, 22, 23, 1 };
	int result = rob(nums);
	cout << result << endl;
	system("pause");
	return 0;
}
int rob(vector<int>& nums) 
{
	if (nums.size() == 0)
	{
		return 0;
	}
	else if (nums.size() == 1)
	{
		return nums[0];
	}
	vector<int> data(nums.size());//记录抢劫这家及右边所有的最高金额
	data[nums.size() - 1] = nums[nums.size() - 1];
	data[nums.size() - 2] = max(data[nums.size() - 1], nums[nums.size() - 2]);
	for (int i = nums.size()-3; i >= 0; i--)
	{
		data[i] = max(data[i + 1], nums[i] + data[i + 2]);
	}
	return data[0];
}