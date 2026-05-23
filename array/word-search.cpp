class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word, int idx, int i, int j){
        if(board[i][j]!=word[idx]) return false;
        if(idx==word.size()-1) return true;
        int n=board.size();
        int m=board[0].size();
        char ch=board[i][j];
        board[i][j]='#';
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for(int k=0; k<4; k++){
            int row=drow[k]+i;
            int col=dcol[k]+j;
            if(row>=0 && row<n && col>=0 && col<m && board[row][col]!='#'){
                if(dfs(board, word, idx+1, row, col)){
                    board[i][j]=ch;
                    return true;
                }
            }
        }
        board[i][j]=ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0]){
                    if(dfs(board, word, 0, i, j)) return true;
                }
            }
        }
        return false;
    }
};