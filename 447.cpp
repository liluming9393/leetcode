#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int numberOfBoomerangs(vector<pair<int, int>>& points);
int main()
{
	pair<int, int> data1(0, 0);
	pair<int, int> data2(1, 0);
	pair<int, int> data3(-1, 0);
	pair<int, int> data4(0, 1);
	pair<int, int> data5(0, -1);
	vector<pair<int, int>> points;
	points.push_back(data1);
	points.push_back(data2);
	points.push_back(data3);
	points.push_back(data4);
	points.push_back(data5);
	int result = numberOfBoomerangs(points);
	cout << result << endl;
	system("pause");
	return 0;
}
int numberOfBoomerangs(vector<pair<int, int>>& points) 
{
	int result = 0;
	map<int, int> data;
	map<int, int>::iterator it;
	int distance = 0;
	pair<int, int> in;
	for (int i = 0; i < points.size(); i++)
	{
		for (int j = 0; j < points.size(); j++)
		{
			if (j != i)
			{
				distance = (points[j].first - points[i].first)*(points[j].first - points[i].first) + (points[j].second - points[i].second) *(points[j].second - points[i].second);
				it = data.find(distance);
				if (it == data.end())
				{
					in.first = distance;
					in.second = 1;
					data.insert(in);
				}
				else
				{
					it->second += 1;
				}
			}
		}
		for (it = data.begin(); it != data.end(); it++)
		{
			if (it->second > 1)
			{
				result = result + (it->second *(it->second - 1));
			}
		}
		data.clear();
	}
	return result;
}