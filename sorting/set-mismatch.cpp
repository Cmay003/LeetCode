class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> hash(n+1, 0);
        for(int num:nums){
            hash[num]++;
        }
        int x, y;
        for(int i=1; i<=n; i++){
            if(hash[i]>1) x=i;
            if(hash[i]==0) y=i;
        }
        return {x,y};
    }
};