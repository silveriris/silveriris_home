#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<vector<vector<bool>>> result;
vector<string>path;

bool IsPlace(vector<vector<bool>>& chessboard,int n,int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (chessboard[i][col]==1)
		{
			return 0;
		}
	}
	for (int i = 0; i < col; i++)
	{
		if (chessboard[row][i] == 1)
		{
			return 0;
		}
	}
	for (int i = row - 1, j = col - 1; i >= 0&&j >= 0; i--, j--)
	{
		if (chessboard[i][j] == 1)
		{
			return 0;
		}
	}
	for (int i = row - 1, j = col + 1; i >= 0&& j < n; i--, j++)
	{
		if (chessboard[i][j] == 1)
		{
			return 0;
		}
	}
	return 1;
}

void backtracking(vector<vector<bool>>& chessboard,int n,int row)
{
	if (row>=n)
	{
		result.push_back(chessboard);
		return;
	}
	for (int col = 0; col < n; col++)
	{
		if (IsPlace(chessboard,n, row, col) == 0)
		{
			continue;
		}
		chessboard[row][col] = 1;
		backtracking(chessboard, n, row + 1);
		chessboard[row][col] = 0;
	}
}
void solveNQueens(int n) {
	vector<vector<bool>> chessboard(n,vector<bool>(n,0));
	backtracking(chessboard,n,0);
	return ;
}
int main() {
	int n;
	cin >> n;
	solveNQueens(n);
	for (vector<vector<bool>> chessboard : result)
	{
		for (vector<bool> line :chessboard)
		{
			for (bool var:line)
			{
				cout << var << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
    return 0;
}