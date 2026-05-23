class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int ones=0;
        int idx=0;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0; i<m; i++){
            int sum=0;
            for(int j=0; j<n; j++){
                sum+=mat[i][j];
            }
            if(sum>ones){
                idx=i;
                ones=sum;
            }
        }
        return {idx, ones};
    }
};