class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char, int> mpp;
        for(int i=0; i<stones.size(); i++){
            mpp[stones[i]]++;
        }
        int count=0;
        for(int i=0; i<jewels.size(); i++){
            for(auto it:mpp){
                if(it.first==jewels[i]){
                    count+=it.second;
                }
            }
        }
        return count;
    }
};