//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//You may assume that each input would have exactly one solution.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
vector<int> twoSum1(vector<int>& nums, int target);
vector<int> twoSum2(vector<int>& nums, int target);
int main()
{
	int sz[3] = { 3, 2, 4 };
	int target = 5;
	vector<int> nums(sz, sz + 3);
	vector<int> result(2);
	result = twoSum2(nums, target);
	cout << result[0] << " " << result[1] << endl;
	system("pause");
	return 0;
}
vector<int> twoSum1(vector<int>& nums, int target)
{
	vector<int> result(2);
	multimap<int, int> obm;
	pair<int, int> t;
	multimap<int, int>::iterator it;
	for (int i = 0; i < nums.size(); i++)
	{
		t.first = nums[i];
		t.second = i;
		obm.insert(t);
	}
	for (int i = 0; i < nums.size(); i++)
	{
		it = obm.find(target - nums[i]);
		if (it != obm.end() && (i != (*it).second))
		{
			if (i < (*it).second)
			{
				result[0] = i;
				result[1] = (*it).second;
				return result;
			}
			else
			{
				result[1] = i;
				result[0] = (*it).second;
				return result;
			}
			
		}
	}
	return result;
}
vector<int> twoSum2(vector<int>& nums, int target)
{
	vector<int> result(2);
	multimap<int, int> obm;
	multimap<int, int>::iterator it;
	for (int i = 0; i < nums.size(); i++)
	{
		it = obm.find(target - nums[i]);
		if (it != obm.end())
		{
			result[0] = (*it).second;
			result[1] = i;
			return result;
		}
		obm.insert(pair<int, int>(nums[i], i));
	}
	return result;
}