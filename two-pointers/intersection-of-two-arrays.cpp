class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> arr1(nums1.begin(),nums1.end());
        unordered_set<int> arr2(nums2.begin(),nums2.end());
        vector<int> result;
        for(auto num:arr1){
            if(arr2.find(num)!=arr2.end()){
                result.push_back(num);
            }
        }
        return result;
    }
};