class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        int x=0;
        stack<char> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && x<k && st.top()>num[i]){
                st.pop();
                x++;
            }
            st.push(num[i]);
        }
        if(x<k){
            while(x!=k){
                st.pop();
                x++;
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int j=0;
        while(ans[j]=='0' && j<ans.size()) j++;
        ans=ans.substr(j);
        if(ans.empty()) ans="0";
        return ans;
    }
};