class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans(friends.size(),0);
        int idx =0;
        for(int i=0; i<order.size(); i++){
            for(int j=0; j<friends.size(); j++){
                if(order[i] == friends[j]){
                    ans[idx++] = order[i];
                }
            }
        }
        return ans;
    }
};