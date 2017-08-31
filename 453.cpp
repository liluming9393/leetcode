#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int minMoves(vector<int>& nums);
int main()
{
	vector<int> nums = { 1, 2, 3 };
	int result = minMoves(nums);
	cout << result << endl;
	system("pause");
	return 0;
}
int minMoves(vector<int>& nums) 
{
	sort(nums.begin(), nums.end());
	int result = 0;
	int max = nums[nums.size() - 1];
	int temp = 0;
	for (int i = nums.size() - 2; i >= 0; i--)
	{
		temp = max - result - nums[i];
		result = result + temp*(nums.size() - 1 - i);
		max = max + temp*(nums.size() - 2 - i);
	}
	return result;
}