class Solution {
public:
    vector<int> row(int k){
        vector<int> ans;
        ans.push_back(1);
        int ncr=1;
        for(int i=1; i<k; i++){
            ncr=ncr * (k-i);
            ncr=ncr/i;
            ans.push_back(ncr);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            ans.push_back(row(i));
        }
        return ans;
    }
};