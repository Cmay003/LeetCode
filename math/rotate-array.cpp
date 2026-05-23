class Solution {
public:
    void rotate(vector<int>& nums, int k) {\
        vector<int> temp;
        int n = nums.size();
        k = k%n;
        temp.insert(temp.begin(), nums.begin()+(n-k), nums.end());
        for(int i = n-k-1; i>=0; i--){
            nums[i+k] = nums[i];
        }
        for(int j=0; j<k; j++){
            nums[j] = temp[j];
        }
        
    }    
};