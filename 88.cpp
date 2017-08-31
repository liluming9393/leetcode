//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//Note:
//You may assume that nums1 has enough space(size that is greater or equal to m + n) to hold additional elements from nums2.
//The number of elements initialized in nums1 and nums2 are m and n respectively.
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
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
void display(vector<int> &data);
int main()
{
	vector<int> nums1 = { 3, 3, 5, 6, 10, 12 };
	int m = 6;
	vector<int> nums2 = { 2, 4, 9, 12, 15 };
	int n = 5;
	nums1.resize(m + n);
	merge(nums1, m, nums2, n);
	display(nums1);
	system("pause");
	return 0;
}
void display(vector<int> &data)
{
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;
	while (i >= 0 && j >= 0)
	{
		if (nums1[i] >= nums2[j])
		{
			nums1[k] = nums1[i];
			k--;
			i--;
		}
		else
		{
			nums1[k] = nums2[j];
			k--;
			j--;
		}
	}
	while (j >= 0)
	{
		nums1[k] = nums2[j];
		k--;
		j--;
	}
}