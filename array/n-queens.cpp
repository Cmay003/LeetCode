class Solution {
public:
    void solve(int n, vector<string>&board, int col, vector<vector<string>>&ans, vector<int>&leftRow, vector<int>&diagUp, vector<int>&diagDown){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(leftRow[row]==0 && diagUp[col+row]==0 && diagDown[n-1+col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                diagUp[col+row]=1;
                diagDown[n-1+col-row]=1;
                solve(n, board, col+1, ans, leftRow, diagUp, diagDown);
                board[row][col]='.';
                leftRow[row]=0;
                diagUp[col+row]=0;
                diagDown[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> board(n, s);
        vector<vector<string>> ans;
        vector<int> leftRow(n, 0), diagUp(2*n-1, 0), diagDown(2*n-1,0);
        solve(n, board, 0, ans, leftRow, diagUp, diagDown);
        return ans;
    }
};