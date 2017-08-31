#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
vector<int> intersect1(vector<int>& nums1, vector<int>& nums2);
vector<int> intersect2(vector<int>& nums1, vector<int>& nums2);
vector<int> intersect3(vector<int>& nums1, vector<int>& nums2);
int main()
{
	vector<int> nums1 = { 54, 93, 21, 73, 84, 60, 18, 62, 59, 89, 83, 89, 25, 39, 41, 55, 78, 27, 65, 82, 94, 61, 12, 38, 76, 5, 35, 6, 51, 48, 61, 0, 47, 60, 84, 9, 13, 28, 38, 21, 55, 37, 4, 67, 64, 86, 45, 33, 41 };
	vector<int> nums2 = { 17, 17, 87, 98, 18, 53, 2, 69, 74, 73, 20, 85, 59, 89, 84, 91, 84, 34, 44, 48, 20, 42, 68, 84, 8, 54, 66, 62, 69, 52, 67, 27, 87, 49, 92, 14, 92, 53, 22, 90, 60, 14, 8, 71, 0, 61, 94, 1, 22, 84, 10, 55, 55, 60, 98, 76, 27, 35, 84, 28, 4, 2, 9, 44, 86, 12, 17, 89, 35, 68, 17, 41, 21, 65, 59, 86, 42, 53, 0, 33, 80, 20 };
	vector<int> result = intersect3(nums1, nums2);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) 
{
	vector<int> result;
	multiset<int> num1;
	multiset<int> num2;
	for (int i = 0; i < nums1.size(); i++)
	{
		num1.insert(nums1[i]);
	}
	for (int i = 0; i < nums2.size(); i++)
	{
		num2.insert(nums2[i]);
	}
	while (num1.size() != 0)
	{
		int temp1 = num1.count(*num1.begin());
		int temp2 = num2.count(*num1.begin());
		if (temp2 == 0)
		{
			num1.erase(*num1.begin());
		}
		else if (temp1 >= temp2)
		{
			for (int j = 0; j < temp2; j++)
			{
				result.push_back(*num1.begin());
			}
			num2.erase(*num1.begin());
			num1.erase(*num1.begin());
		}
		else if (temp1 < temp2)
		{
			for (int j = 0; j < temp1; j++)
			{
				result.push_back(*num1.begin());
			}
			num2.erase(*num1.begin());
			num1.erase(*num1.begin());
		}
	}
	return result;
}
vector<int> intersect2(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> result;
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	int i = 0;
	int j = 0;
	int count1 = 0;
	int count2 = 0;
	while (i < nums1.size() && j < nums2.size())
	{
		if (nums1[i] != nums2[j])
		{
			if (nums1[i] < nums2[j])
			{
				if (i < nums1.size() - 1)
				{
					while (nums1[i] == nums1[i + 1])
					{
						i++;
						if (i == nums1.size() - 1)
						{
							break;
						}
					}
				}
				i++;
			}
			else if (nums1[i] > nums2[j])
			{
				if (j < nums2.size() - 1)
				{
					while (nums2[j] == nums2[j + 1])
					{
						j++;
						if (j == nums2.size() - 1)
						{
							break;
						}
					}
				}
				j++;
			}
		}
		else if (nums1[i] == nums2[j])
		{
			if (i < nums1.size() - 1)
			{
				while (nums1[i] == nums1[i + 1])
				{
					i++;
					count1++;
					if (i == nums1.size() - 1)
					{
						break;
					}
				}
				i++;
				count1++;
			}
			else
			{
				count1++;
				i++;
			}
			if (j < nums2.size() - 1)
			{
				while (nums2[j] == nums2[j + 1])
				{
					j++;
					count2++;
					if (j == nums2.size() - 1)
					{
						break;
					}
				}
				j++;
				count2++;
			}
			else
			{
				count2++;
				j++;
			}
			if (count1 <= count2)
			{
				for (int k = 0; k < count1; k++)
				{
					result.push_back(nums1[i - 1]);
				}
			}
			else
			{
				for (int k = 0; k < count2; k++)
				{
					result.push_back(nums1[i - 1]);
				}
			}
			count1 = 0;
			count2 = 0;
		}
	}
	return result;
}
vector<int> intersect3(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> result;
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	int i = 0;
	int j = 0;
	int count1 = 0;
	int count2 = 0;
	while (i < nums1.size() && j < nums2.size())
	{
		if (nums1[i] != nums2[j])
		{
			if (nums1[i] < nums2[j])
			{
				i++;
				while (i < nums1.size())
				{
					if (nums1[i] != nums1[i - 1])
					{
						break;
					}
					i++;
				}
			}
			else if (nums1[i] > nums2[j])
			{
				j++;
				while (j < nums2.size())
				{
					if (nums2[j] != nums2[j - 1])
					{
						break;
					}
					j++;
				}
			}
		}
		else
		{
			i++;
			count1++;
			while (i < nums1.size())
			{
				if (nums1[i] != nums1[i - 1])
				{
					break;
				}
				i++;
				count1++;
			}
			j++;
			count2++;
			while (j < nums2.size())
			{
				if (nums2[j] != nums2[j - 1])
				{
					break;
				}
				j++;
				count2++;
			}
			if (count1 <= count2)
			{
				for (int k = 0; k < count1; k++)
				{
					result.push_back(nums1[i - 1]);
				}
			}
			else
			{
				for (int k = 0; k < count2; k++)
				{
					result.push_back(nums1[i - 1]);
				}
			}
			count1 = 0;
			count2 = 0;
		}
	}
	return result;
}