class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int ans=0;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int el=st.top();
                st.pop();
                int ns=i, ps=(st.empty())?-1:st.top();
                ans=max(ans,(heights[el]*(ns-ps-1)));
            }
            st.push(i);
        }
        while(!st.empty()){
            int el=st.top();
            st.pop();
            int ns=n;
            int ps=(st.empty())?-1:st.top();
            ans=max(ans,(heights[el]*(ns-ps-1)));
        }
        return ans;
    }
};