//Given two arrays, write a function to compute their intersection.
//Example:Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return[2].
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
vector<int> intersection1(vector<int>& nums1, vector<int>& nums2);
vector<int> intersection2(vector<int>& nums1, vector<int>& nums2);
int main()
{
	vector<int> nums1 = { 1, 2, 2, 3 };
	vector<int> nums2 = { 2, 2, 3 };
	vector<int> result = intersection2(nums1, nums2);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) 
{
	vector<int> result;
	set<int> temp;

	for (int i = 0; i < nums1.size(); i++)
	{
		for (int j = 0; j < nums2.size(); j++)
		{
			if (nums1[i] == nums2[j])
			{
				temp.insert(nums1[i]);
				break;
			}
		}
	}
	set<int>::iterator it;
	for (it = temp.begin(); it != temp.end(); it++)
	{
		result.push_back(*it);
	}
	return result;
}
vector<int> intersection2(vector<int>& nums1, vector<int>& nums2)
{
	set<int> num1;
	set<int> num2;
	set<int>::iterator it1;
	set<int>::iterator it2;
	vector<int> result;
	for (int i = 0; i < nums1.size(); i++)
	{
		num1.insert(nums1[i]);
	}
	for (int i = 0; i < nums2.size(); i++)
	{
		num2.insert(nums2[i]);
	}
	if (num1.size() <= num2.size())
	{
		for (it1 = num1.begin(); it1 != num1.end(); it1++)
		{
			it2 = num2.find(*it1);
			if (it2 != num2.end())
			{
				result.push_back(*it1);
			}
		}
	}
	else
	{
		for (it1 = num2.begin(); it1 != num2.end(); it1++)
		{
			it2 = num1.find(*it1);
			if (it2 != num1.end())
			{
				result.push_back(*it1);
			}
		}
	}
	return result;
}