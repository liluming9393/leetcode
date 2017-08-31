//Given an index k, return the kth row of the Pascal's triangle.
//For example, given k = 3,
//Return[1, 3, 3, 1].
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
vector<int> getRow(int rowIndex);
int main()
{
	int rowIndex = 3;
	vector<int> result;
	result = getRow(rowIndex);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
vector<int> getRow(int rowIndex)
{
	rowIndex += 1;
	vector<vector<int>> temp(rowIndex);
	temp[0].push_back(1);
	for (int i = 1; i < rowIndex; i++)
	{
		temp[i].push_back(1);
		for (int j = 1; j < i; j++)
		{
			temp[i].push_back(temp[i - 1][j - 1] + temp[i - 1][j]);
		}
		temp[i].push_back(1);
	}
	vector<int> result;
	for (int i = 0; i < temp[rowIndex-1].size(); i++)
	{
		result.push_back(temp[rowIndex-1][i]);
	}
	return result;
}