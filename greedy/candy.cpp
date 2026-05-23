class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int ans=0;
        vector<int> candies(n,1);
        for(int i=0; i<n; i++){
            if(i>0 && ratings[i]>ratings[i-1]){
                candies[i]=candies[i-1]+1;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(i<n-1 && ratings[i]>ratings[i+1]){
                candies[i]=max(candies[i], candies[i+1]+1);
            }
            ans+=candies[i];
        }
        return ans;
    }
};