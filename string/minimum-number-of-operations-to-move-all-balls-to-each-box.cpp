class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        vector<int> idx;
        for(int i=0; i<boxes.size(); i++){
            if(boxes[i]=='1'){
                idx.push_back(i);
            }
        }
        for(int i=0; i<boxes.size(); i++){
            int sum=0;
            for(int j=0; j<idx.size(); j++){
                sum+=abs(idx[j]-i);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};