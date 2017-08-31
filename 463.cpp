//You are given a map in form of a two - dimensional integer grid where 1 represents land and 0 represents water.
//Grid cells are connected horizontally / vertically(not diagonally).
//The grid is completely surrounded by water, and there is exactly one island(i.e., one or more connected land cells).
//The island doesn't have "lakes" (water inside that isn't connected to the water around the island).One cell is a square with side length 1.
//The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int islandPerimeter(vector<vector<int>>& grid);
int main()
{
	vector<vector<int>> grid(4);
	for (int i = 0; i < 4; i++)
	{
		grid[i].resize(4);
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			grid[i][j] = 0;
		}
	}
	grid[0][1] = 1;
	grid[1][0] = 1;
	grid[1][1] = 1;
	grid[1][2] = 1;
	grid[2][1] = 1;
	grid[3][0] = 1;
	grid[3][1] = 1;
	int result = islandPerimeter(grid);
	cout << result << endl;
	system("pause");
	return 0;
}
int islandPerimeter(vector<vector<int>>& grid) 
{
	int result = 0;
	int height = grid.size();
	if (height == 0)
	{
		return 0;
	}
	int width = grid[0].size();
	vector<vector<int>> data(height + 2);
	for (int i = 0; i < height + 2; i++)
	{
		data[i].resize(width + 2);
	}
	for (int i = 1; i < data.size() - 1; i++)
	{
		for (int j = 1; j < data[0].size() - 1; j++)
		{
			data[i][j] = grid[i - 1][j - 1];
		}
	}
	int count = 0;
	for (int i = 1; i < data.size() - 1; i++)
	{
		for (int j = 1; j < data[0].size() - 1; j++)
		{
			if (data[i][j] == 1)
			{
				if (data[i - 1][j] == 0)
				{
					count++;
				}
				if (data[i + 1][j] == 0)
				{
					count++;
				}
				if (data[i][j - 1] == 0)
				{
					count++;
				}
				if (data[i][j + 1] == 0)
				{
					count++;
				}
				result = result + count;
				count = 0;
			}
		}
	}
	return result;
}