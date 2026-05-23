class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n=words.size();
        long long ans=0;
        unordered_map<string, long long> mpp;
        for(string &w:words){
            int shift=w[0]-'a';
            string temp=w;
            for(char &c:temp){
                c=((c-'a')-shift+26)%26 + 'a';
            }
            mpp[temp]++;
        }
        for(auto it:mpp){
            long long cnt=it.second;
            ans+=(cnt*(cnt - 1)/2);
        }
        return ans;
    }
};