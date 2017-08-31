/*Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output ¡°Fizz¡± instead of the number and for the multiples of five output ¡°Buzz¡±.For numbers which are multiples of both three and five output ¡°FizzBuzz¡±.
Example:
n = 15,
Return :
[
	"1",
	"2",
	"Fizz",
	"4",
	"Buzz",
	"Fizz",
	"7",
	"8",
	"Fizz",
	"Buzz",
	"11",
	"Fizz",
	"13",
	"14",
	"FizzBuzz"
]*/
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
vector<string> fizzBuzz(int n);
int main()
{
	int n;
	while (cin>>n)
	{
		vector<string> result;
		result = fizzBuzz(n);
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << endl;
		}
	}

	system("pause");
	return 0;
}
vector<string> fizzBuzz(int n) 
{
	vector<string> result;
	string temp;
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0 && i % 5 != 0)
		{
			temp = "Fizz";
			result.push_back(temp);
		}
		else if (i % 3 != 0 && i % 5 == 0)
		{
			temp = "Buzz";
			result.push_back(temp);
		}
		else if (i % 3 == 0 && i % 5 == 0)
		{
			temp = "FizzBuzz";
			result.push_back(temp);
		}
		else if (i % 3 != 0 && i % 5 != 0)
		{
			int num = i;
			temp.clear();
			while (num != 0)
			{
				temp = (char)(num % 10 + '0') + temp;
				num = num / 10;
			}
			result.push_back(temp);
		}
	}
	return result;
}