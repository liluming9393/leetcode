//Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k);
int main()
{
	int s[] = { 1, 4, 6, 9, 2, 1, 2, 4, 9 };
	vector<int> nums(s, s + 9);
	int k = 5;
	bool result = containsNearbyDuplicate(nums, k);
	cout << result << endl;
	system("pause");
	return 0;
}
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	set<int> data(nums.begin(), nums.end());
	if (data.size() == nums.size())
		return false;
	set<int> obs;
	pair<set<int>::iterator, bool>res;
	for (int i = 0; i <= k; i++)
		obs.insert(nums[i]);
	if (obs.size() <= k)
		return true;
	else
	{
		for (int i = k + 1; i < nums.size(); i++)
		{
			obs.erase(nums[i - k - 1]);
			res = obs.insert(nums[i]);
			if (res.second == false)
				return true;
		}
	}
	return false;
}