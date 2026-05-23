class Solution {
public:
    long long minSum(vector<int> &arr){
        int n=arr.size();
        stack<int> st;
        long long ans=0;
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || arr[st.top()]>arr[i])){
                int mid=st.top();
                st.pop();
                int prev=(st.empty())?-1:st.top();
                int l=mid-prev;
                int r=i-mid;
                ans+=(1LL*arr[mid]*l*r);
            }
            st.push(i);
        }
        return ans;
    }
    long long maxSum(vector<int> &arr){
        int n=arr.size();
        stack<int> st;
        long long ans=0;
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || arr[st.top()]<arr[i])){
                int mid=st.top();
                st.pop();
                int prev=(st.empty())?-1:st.top();
                int l=mid-prev;
                int r=i-mid;
                ans+=(1LL*arr[mid]*l*r);
            }
            st.push(i);
        }   
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        return maxSum(nums)-minSum(nums);
    }
};