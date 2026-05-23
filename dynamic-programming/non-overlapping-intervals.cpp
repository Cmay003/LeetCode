class Solution {
public:
    static bool con(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), con);
        int n=intervals.size();
        int ans=0;
        int last=intervals[0][1];
        for(int i=1; i<n; i++){
            if(intervals[i][0]<last){
                ans++;
            }
            else{
                last=intervals[i][1];
            }
        }
        return ans;
    }
};