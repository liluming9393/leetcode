//Given an array of integers, every element appears twice except for one.Find that single one.
//Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int singleNumber1(vector<int>& nums);
int singleNumber2(vector<int>& nums);
int main()
{
	int test[7] = { 1, 2, 1, 15, 2, 3, 3 };
	vector<int> num(test, test + 7);
	int result = singleNumber2(num);
	cout << result << endl;
	system("pause");
	return 0;
}
int singleNumber1(vector<int>& nums) 
{
	set<int> num;
	int length1;
	int length2;
	for (int i = 0; i < nums.size(); i++)
	{
		length1 = num.size();
		num.insert(nums[i]);
		length2 = num.size();
		if (length2 == length1)
		{
			num.erase(nums[i]);
		}
	}
	return *num.begin();
}
int singleNumber2(vector<int>& nums)
{
	int result = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		result = result^nums[i];
	}
	return result;
}