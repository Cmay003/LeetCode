class Solution {
public:
    int area(vector<int> &arr){
        int n=arr.size();
        int ans=0;
        stack<int> st;
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || arr[st.top()]>arr[i])){
                int el=st.top();
                st.pop();
                int ps=(st.empty())?-1:st.top();
                int ns=i;
                ans=max(ans, arr[el]*(ns-ps-1));
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<int> prefix(m, 0);
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1') prefix[j]++;
                else prefix[j]=0;
            }
            ans=max(ans, area(prefix));
        }
        return ans;
    }
};