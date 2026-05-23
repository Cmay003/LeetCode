class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int i=n-1;
        set<int> st;
        while(i>=0){
            if(st.count(nums[i])) break;
            st.insert(nums[i]);
            i--;
        }
        int ans=i+1;
        return ceil((double)ans/3);
    }
};