//Determine if a Sudoku is valid, according to : Sudoku Puzzles - The Rules.
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//A partially filled sudoku which is valid.
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
bool isValidSudoku(vector<vector<char>>& board);
int main()
{
	//vector<string> data = { ".87654321", "2........", "3........", "4........", "5........", "6........", "7........", "8........", "9........" };
	//vector<string> data = { "..5.....6", "....14...", ".........", ".....92..", "5....2...", ".......3.", "...54....", "3.....42.", "...27.6.." };
	vector<string> data = { "..5......", "...8...3.", ".5..2....", ".........", "........9", "......4..", "........7", ".1.......", "24....9.." };
	vector<vector<char>> board(9);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			board[i].push_back(data[i][j]);
		}
	}
	int result = isValidSudoku(board);
	cout << result << endl;
	system("pause");
	return 0;
}
bool isValidSudoku(vector<vector<char>>& board)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			//判断行
			for (int k = 0; k < 9; k++)
			{
				if (board[i][j] != '.' && board[i][j] == board[i][k] && k!=j)
				{
					return false;
				}
			}
			//判断列
			for (int k = 0; k < 9; k++)
			{
				if (board[i][j] != '.' && board[i][j] == board[k][j] && k!=i)
				{
					return false;
				}
			}
			//判断格子
			for (int k = i / 3 * 3; k < (i / 3 * 3 + 3) ; k++)
			{
				for (int m = j / 3 * 3; m < (j / 3 * 3 + 3) ; m++)
				{
					if (board[i][j] != '.' && board[i][j] == board[k][m] && k != i && m != j)
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}