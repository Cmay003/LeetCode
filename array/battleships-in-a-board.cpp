class Solution {
public:
    const int drow[4]={-1,0,1,0};
    const int dcol[4]={0,-1,0,1};
    void dfs(int n, int m, vector<vector<char>>& board, vector<vector<int>>&visited, int i, int j){
        visited[i][j]=1;
        for(int k=0; k<4; k++){
            int row=drow[k]+i;
            int col=dcol[k]+j;
            if(row>=0 && row<n && col>=0 && col<m && board[row][col]=='X' && !visited[row][col]){
                dfs(n, m, board, visited, row, col);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int ans=0;
        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='X' && !visited[i][j]){
                    dfs(n,m,board,visited,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};