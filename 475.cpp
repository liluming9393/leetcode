/*Winter is coming!Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.
Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.
So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.
Note:
Numbers of houses and heaters you are given are non - negative and will not exceed 25000.
Positions of houses and heaters you are given are non - negative and will not exceed 10 ^ 9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
Example 1 :
Input : [1, 2, 3], [2]
Output : 1
Explanation : The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2 :
Input : [1, 2, 3, 4], [1, 4]
Output : 1
Explanation : The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.*/
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int findRadius(vector<int>& houses, vector<int>& heaters);
int main()
{
	vector<int> houses = { 35308228, 158374933, 75260298, 824938981, 595028635, 962408013, 137623865, 997389814, 20739063 };
	vector<int> heaters = { 635339425, 654001669, 777724115, 269220094, 34075629, 478446501, 864546517 };
	int result = findRadius(houses, heaters);
	cout << result << endl;
	system("pause");
	return 0;
}
int findRadius(vector<int>& houses, vector<int>& heaters) 
{
	sort(houses.begin(), houses.end());
	sort(heaters.begin(), heaters.end());
	int result = 0;
	int i = 0;
	int j = 0;
	if (heaters.size() == 1)
	{
		return max((heaters[0] - houses[0]), (houses[houses.size() - 1] - heaters[0]));
	}
	while (houses[i] <= heaters[j] && i < houses.size())
	{
		i++;
		result = heaters[0] - houses[0];
	}
	if (i == houses.size() || heaters.size() == 1)
	{
		return result;
	}
	while (i < houses.size() && (j + 1) < heaters.size())
	{
		if (houses[i] > heaters[j + 1])
		{
			j++;
		}
		if ((j + 1) == heaters.size())
		{
			break;
		}
		if (houses[i] >= heaters[j] && houses[i] <= heaters[j + 1])
		{
			result = max(result, min((houses[i] - heaters[j]), (heaters[j + 1] - houses[i])));
			i++;
		}
	}
	if (i == houses.size())
	{
		return result;
	}
	result = max(result, (houses[houses.size() - 1] - heaters[heaters.size() - 1]));
	return result;
}