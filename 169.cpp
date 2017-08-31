//Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//You may assume that the array is non - empty and the majority element always exist in the array.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
using namespace std;
int majorityElement1(vector<int>& nums);
int majorityElement2(vector<int>& nums);
int majorityElement3(vector<int>& nums);

int main()
{
	int test[6] = { 2, 7, 2, 15, 2, 2 };
	vector<int> num(test, test + 6);
	int result = majorityElement3(num);
	cout << result << endl;
	system("pause");
	return 0;
}
int majorityElement1(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	return nums[nums.size() / 2];
}
int majorityElement2(vector<int>& nums)
{
	map<int, int>data;
	map<int, int>::iterator it;
	pair<int, int> p;
	p.second = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		it = data.find(nums[i]);
		if (it == data.end())
		{
			p.first = nums[i];
			data.insert(p);
			if (nums.size() == 1)
				return nums[i];
		}
		else
		{
			(*it).second++;
			if ((*it).second > nums.size() / 2)
				return (*it).first;
		}
	}
	return -1;
}
int majorityElement3(vector<int>& nums)
{
	int result = nums[0];
	int count = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (result == nums[i])
		{
			count++;
		}
		else
		{
			count--;
			if (count == 0)
			{
				result = nums[i + 1];
			}
		}
	}
	return result;
}