class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> map;
        for(int i=0; i<s.size(); i++){
            map[s[i]]++;
        }
        int Vmax = 0;
        int Cmax = 0;
        for(auto x: map){
            if(x.first=='a'||x.first=='e'||x.first=='i'||x.first=='o'||x.first=='u'){
                if(x.second > Vmax){
                Vmax = x.second;
                }
            }
            else{
                if(x.second > Cmax){
                Cmax = x.second;
                }
            }
        }
        int max = Vmax+Cmax;
        return max;
    }
};