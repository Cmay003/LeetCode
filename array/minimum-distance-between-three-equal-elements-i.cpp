class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int dis = INT_MAX;
        if(n<3) return -1;
        unordered_map<int, vector<int>> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto num:mpp){
            int sum=0;
            if(num.second.size() >= 3){
                for(int i=0; i+2<num.second.size(); i++){
                sum=abs(num.second[i]-num.second[i+1])+abs(num.second[i+1]-num.second[i+2])+abs(num.second[i+2]-num.second[i]);
                dis = min(dis,sum);
            }
            }
            
        }
        if(dis==INT_MAX) return -1;
        return dis;
    }
};