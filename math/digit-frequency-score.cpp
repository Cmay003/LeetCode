class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int> mpp;
        while(n>0){
            int digit=n%10;
            mpp[digit]++;
            n/=10;
        }
        int ans=0;
        for(auto i:mpp){
            ans+=i.first*i.second;
        }
        return ans;
    }
};