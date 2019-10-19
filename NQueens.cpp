#include<bits/stdc++.h>
#include<iostream>
#define N 100
using namespace std;
int board_size;
bool safe(int board[N][N],int row,int column)
{
	int i,j;
	for(i=0;i<board_size;i++)
		if(board[row][i]==1&&i!=column)
			return false;
	for(i=0;i<board_size;i++)
		if(board[i][column]==1&&i!=row)
				return false;
	for(i=-board_size;i<=board_size;i++)
		if(i!=0&&i+row>-1&&i+row<board_size)
			if(i!=0&&i+column>-1&&i+column<board_size)
				if(board[i+row][i+column]==1)
					return false;
	for(i=-board_size;i<=board_size;i++)
		if(i!=0&&-i+row>-1&&-i+row<board_size)
			if(i!=0&&i+column>-1&&i+column<board_size)
				if(board[-i+row][i+column]==1)
					return false;
	return true;
}
bool assign_col(int board[N][N],int row_no)
{
	if(row_no==board_size)
		return true;
	int i,j,k;
	for(j=0;j<board_size;j++)
	{
		board[row_no][j]=1;
		if(safe(board,row_no,j))
			if(assign_col(board,row_no+1))
				return true;
		board[row_no][j]=0;
	}
	return false;
}
int main()
{
	char Piece[2]={'_','I'};
	cin>>board_size;
	int i,j,a[N][N];
	for(i=0;i<board_size;i++)
		for(j=0;j<board_size;j++)
			a[i][j]=0;
	if(assign_col(a,0))
		for(i=0;i<board_size;i++)
			for(j=0;j<board_size;j++)
				cout<<Piece[a[i][j]]<<(j==board_size-1?"\n":" ");
	else
		cout<<"no solution";
	return 0;
}