class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        map<char, int> mpp;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
        }
        int maxi=0;
        for(auto it:mpp){
            if(it.second>maxi) maxi=it.second;
        }
        string ans="";
        while(maxi!=0){
            for(auto it:mpp){
                if(it.second==maxi){
                    for(int k=0; k<it.second; k++){
                        ans.push_back(it.first);
                    }
                } 
            }
            maxi--;
        }
        return ans;
    }
};