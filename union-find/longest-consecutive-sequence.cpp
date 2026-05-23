class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int ans=1;
        unordered_set<int> arr;
        for(int i=0; i<n; i++){
            arr.insert(nums[i]);
        }
        for(auto it: arr){
            if(arr.find(it-1)==arr.end()){
                int count=1;
                int x=it;
                while(arr.find(x+1)!=arr.end()){
                    count++;
                    x++;
                }
                ans=max(ans, count);
            }
            
        }
        return ans;
    }
};