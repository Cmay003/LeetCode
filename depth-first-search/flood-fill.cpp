class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int prev=image[sr][sc];
        image[sr][sc]=color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int drow[4]={0,-1,0,1};
        int dcol[4]={-1,0,1,0};
        while(!q.empty()){
            auto [r,c]=q.front(); q.pop();
            for(int i=0; i<4; i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && row<n && col>=0 && col<m && image[row][col]==prev && image[row][col]!=color){
                    image[row][col]=color;
                    q.push({row,col});
                }
            }
        }
        return image;
    }
};