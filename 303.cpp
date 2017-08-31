//Given an integer array nums, find the sum of the elements between indices i and j(i ¡Ü j), inclusive.
//Example:
//Given nums = [-2, 0, 3, -5, 2, -1]
//sumRange(0, 2) -> 1
//sumRange(2, 5) -> - 1
//sumRange(0, 5) -> - 3
//Note :
//	 You may assume that the array does not change.
//	 There are many calls to sumRange function.
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
class NumArray {
private:
	vector<int> sum;
public:
	NumArray(vector<int> &nums) {
		if (nums.size() != 0)
		{
			sum.push_back(nums[0]);
			for (int i = 1; i < nums.size(); i++)
			{
				sum.push_back(sum[i - 1] + nums[i]);
			}
		}
	}

	int sumRange(int i, int j) {
		if (i == 0)
		{
			return sum[j];
		}
		else
		{
			return sum[j] - sum[i - 1];
		}
	}
};
int main()
{
	vector<int> nums = { 1, 2, 3, 4, 5 };
	NumArray numarray(nums);
	int result = numarray.sumRange(1, 3);
	cout << result << endl;
	system("pause");
	return 0;
}