class Solution {
public:
    vector<int> NSE(vector<int>& arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=(st.empty())?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> PSE(vector<int>& arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=NSE(arr);
        vector<int> pse=PSE(arr);
        int ans=0;
        int mod=1e9+7;
        for(int i=0; i<arr.size(); i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            ans=(ans+((long long)arr[i]*left*right*1LL)%mod)%mod;
        }
        return ans;
    }
};