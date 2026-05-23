class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0, ans=0;
        int totG=0, totC=0;
        for(int i=0; i<gas.size(); i++){
            totG+=gas[i];
            totC+=cost[i];
            total+=gas[i]-cost[i];
            if(total<0){
                ans=i+1;
                total=0;
            }
        }
        if(totG<totC) return -1;
        return ans;
    }
};