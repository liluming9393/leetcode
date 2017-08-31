/*You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is.Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position(called "bulls") and how many digits match the secret number but locate in the wrong position(called "cows").Your friend will use successive guesses and hints to eventually derive the secret number.

For example :

Secret number : "1807"
Friend's guess: "7810"
Hint : 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
	   Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

	   Please note that both secret number and friend's guess may contain duplicate digits, for example:

	   Secret number : "1123"
	   Friend's guess: "0111"
	   In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
	   You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.*/
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
string getHint(string secret, string guess);
int main()
{
	while (1)
	{
		string secret;
		getline(cin, secret);
		string guess;
		getline(cin, guess);
		string result = getHint(secret, guess);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
string getHint(string secret, string guess)
{
	int bulls = 0;
	int cows = 0;
	int count1[10] = { 0 };
	int count2[10] = { 0 };
	for (int i = 0; i < secret.size(); i++)
	{
		if (secret[i] == guess[i])
		{
			bulls++;
		}
		else
		{
			count1[secret[i] - '0']++;
			count2[guess[i] - '0']++;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cows += min(count1[i], count2[i]);
	}
	string result;
	result = 'B' + result;
	if (cows == 0)
	{
		result = '0' + result;
	}
	while (cows != 0)
	{
		result = (char)(cows % 10 + '0') + result;
		cows = cows / 10;
	}
	result = 'A' + result;
	if (bulls == 0)
	{
		result = '0' + result;
	}
	while (bulls != 0)
	{
		result = (char)(bulls % 10 + '0') + result;
		bulls = bulls / 10;
	}
	return result;
}