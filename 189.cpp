//Rotate an array of n elements to the right by k steps.
//For example, with n = 7 and k = 3, the array[1, 2, 3, 4, 5, 6, 7] is rotated to[5, 6, 7, 1, 2, 3, 4].
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
void rotate(vector<int>& nums, int k);
int main()
{
	int s[] = { 1, 2, 3, 4, 5, 6, 7 };
	int k = 3;
	vector<int> nums(s, s + 7);
	rotate(nums, k);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
void rotate(vector<int>& nums, int k)
{
	k = k%nums.size();
	vector<int> data;
	for (int i = nums.size() - k; i < nums.size(); i++)
		data.push_back(nums[i]);
	for (int i = 0; i < nums.size() - k;i++)
		data.push_back(nums[i]);
	nums = data;
}