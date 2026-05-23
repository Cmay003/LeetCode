class Solution {
public:
    int maxDistinct(string s) {
        map<char,int>mpp;
        int n = s.size();
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        int count =0;
        for(auto it:mpp){
            if(it.second>0){
                count++;
            }
        }
        return count;
    }
};