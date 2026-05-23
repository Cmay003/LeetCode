class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int> nums2(n);
        for(int i=0; i<n; i++){
            if(nums1[i]%2==0){
                return true;
            }
            else{
                return true;
            }
        }
        return false;
    }
};