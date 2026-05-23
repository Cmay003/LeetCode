class Solution {
public:
    int firstUniqueFreq(vector<int>& nums){
        unordered_map<int ,int> m1 , m2 ; 
        for(int val : nums){
            m1[val]++ ;
        }
        for(auto val : m1){
            m2[val.second]++ ;
        }
        for(int val : nums){
           if( m2[m1[val]] == 1){
            return val ;
           }
        }
        return -1;
    }
};