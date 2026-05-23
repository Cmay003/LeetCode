class Solution {
public:
    int mostFrequentEven(vector<int>& nums){        
        unordered_map<int,int>m1;
        for(int val:nums){
            if(val%2 == 0){
                m1[val]++ ;
            }
        }
        int ans = -1 ;
        int freq = -1 ;
        for(int val:nums){
            if(val%2 == 0){
                if( m1[val] > freq || (m1[val]) == freq && val < ans){
                    freq = m1[val] ;
                    ans = val ;
                }
            }
        }
        return ans ;
    }
};