class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>&visited, vector<vector<char>>&board){
        int m=board.size();
        int n=board[0].size();
        visited[r][c]=1;
        int drow[4]={0,-1,0,1};
        int dcol[4]={-1,0,1,0};
        for(int i=0; i<4; i++){
            int row=r+drow[i];
            int col=c+dcol[i];
            if(row>=0 && row<m && col>=0 && col<n && !visited[row][col] && board[row][col]=='O'){
                dfs(row, col, visited, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            if(!visited[i][0] && board[i][0]=='O'){
                dfs(i, 0, visited, board);
            }
            if(!visited[i][n-1] && board[i][n-1]=='O'){
                dfs(i, n-1, visited, board);
            }
        }
        for(int i=0; i<n; i++){
            if(!visited[0][i] && board[0][i]=='O'){
                dfs(0, i, visited, board);
            }
            if(!visited[m-1][i] && board[m-1][i]=='O'){
                dfs(m-1, i, visited, board);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};