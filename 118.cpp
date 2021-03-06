/*Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
	[1],
	[1, 1],
	[1, 2, 1],
	[1, 3, 3, 1],
	[1, 4, 6, 4, 1]
]*/
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
vector<vector<int>> generate1(int numRows);
int main()
{
	int numRows = 5;
	vector<vector<int>> result = generate1(numRows);
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
vector<vector<int>> generate1(int numRows) 
{
	if (numRows == 0)
	{
		vector<vector<int>> result;
		return result;
	}
	vector<vector<int>> result(numRows);
	result[0].push_back(1);
	for (int i = 1; i < numRows; i++)
	{
		result[i].push_back(1);
		for (int j = 1; j < i; j++)
		{
			result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
		}
		result[i].push_back(1);
	}
	return result;
}