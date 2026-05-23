class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> arr1, arr2;
        for(int i=0; i<nums.size(); i++){
            if(i%2==0) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }  
        sort(arr1.begin(),arr1.end());    
        sort(arr2.rbegin(),arr2.rend());    
        int j=0,k=0;
        for(int i=0; i<nums.size(); i++){
            if(i%2==0) nums[i]=arr1[j++];
            else nums[i]=arr2[k++];
        }
        return nums;
    }
};