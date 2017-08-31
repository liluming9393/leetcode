//Given an array of integers, find if the array contains any duplicates.
//Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
using namespace std;
bool containsDuplicate1(vector<int>& nums);
bool containsDuplicate2(vector<int>& nums);
bool containsDuplicate3(vector<int>& nums);

int main()
{
	int test[6] = { 1, 2, 4, 15, 6, 3 };
	vector<int> num(test, test + 6);
	bool result = containsDuplicate3(num);
	cout << result << endl;
	system("pause");
	return 0;
}
bool containsDuplicate1(vector<int>& nums)
{
	set<int> num(nums.begin(), nums.end());
	if (nums.size() == num.size())
		return false;
	else
		return true;
}
bool containsDuplicate2(vector<int>& nums)
{
	set<int> num;
	set<int>::iterator it;
	for (int i = 0; i < nums.size(); i++)
	{
		it = num.find(nums[i]);
		if (it != num.end())
			return true;
		else
			num.insert(nums[i]);
	}
	return false;
}
bool containsDuplicate3(vector<int>& nums)
{
	if (nums.size() == 0)
		return false;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 1; i++)
	{
		if (nums[i] == nums[i + 1])
			return true;
	}
	return false;
}
