class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size();
        vector<vector<int>> board(3,vector<int>(3,-1));
        int turn=0;
        for(auto it:moves){
            if(turn==0){
                board[it[0]][it[1]]=1;
                turn=1;
            }
            else{
                board[it[0]][it[1]]=0;
                turn=0;
            }
        }
        int ans=-1;
        for(int i=0; i<3; i++){
            if(board[i][0]==1 && board[i][1]==1 && board[i][2]==1) ans=1;
            if(board[0][i]==0 && board[1][i]==0 && board[2][i]==0) ans=0;
        }
        if((board[0][0]==1 && board[1][1]==1 && board[2][2]==1) || (board[0][2]==1 && board[1][1]==1 && board[2][0]==1)) ans=1;
        if((board[0][0]==0 && board[1][1]==0 && board[2][2]==0) || (board[0][2]==0 && board[1][1]==0 && board[2][0]==0)) ans=0;
        if(ans==0) return "B";
        else if(ans==1) return "A";
        else return "Draw";
    }
}; 