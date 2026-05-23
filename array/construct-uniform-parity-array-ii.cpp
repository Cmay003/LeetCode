class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int> nums2(n);
        int mini=*min_element(nums1.begin(), nums1.end());
        for(int i=0; i<n; i++){
            if(nums1[i]==mini) continue;
            if(nums1[i]%2==mini%2) continue;
            if(nums1[i]-mini>=1 && (nums1[i]-mini)%2==mini%2) continue;
            return false;
        }
        return true;
    }
};