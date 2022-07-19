/* The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively. */

class Solution {
public:
    
    
     bool pos(int row,int column,vector<string>&board,int n )
    {
        int i=row;
        int j=column;
        while(column>=0)
        {
            if(board[row][column]=='Q')
            return false;
            column--;
        }
        row=i;
        column=j;
        while(row>=0 && column>=0)
        {
            if(board[row][column]=='Q')
            return false;
            row--;
            column--;
        }
        row=i;
        column=j;
        while(row<n && column>=0)
        {
            if(board[row][column]=='Q')
            return false;
            row++;
            column--;
        }
        return true;
    }
    

    void fun(int j,int n,vector<vector<string>>&ans,vector<string>&board)
    {
        if(j==n)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(pos(i,j,board,n))
            {
                board[i][j]='Q';
                fun(j+1,n,ans,board);
                board[i][j]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        board[i]=s;
        fun(0,n,ans,board);
        return ans;
    }
};