class Solution {
public:
    int maxElem(vector<vector<int>>& mat, int col){
        int maxi=INT_MIN;
        int idx=-1;
        for(int i=0; i<mat.size(); i++){
            if(mat[i][col]>maxi){
                maxi = mat[i][col];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0, high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row = maxElem(mat, mid);
            int left= (mid>0) ? mat[row][mid-1]:-1;
            int right= (mid+1<n) ? mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row, mid};
            }
            else if(left>mat[row][mid]) high=mid-1;
            else low=mid+1;
        }
        return {};
    }
};