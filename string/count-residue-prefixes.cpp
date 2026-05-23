class Solution {
public:
    int residuePrefixes(string s) {
        int n=s.size();
        int ans=0;
        for(int i=n-1; i>=0; i--){
            set<char> st;
            int len=i+1;
            for(int j=0; j<=i; j++){
                st.insert(s[j]);
            }
            if(st.size()==len%3){
                ans++;
            }
        }
        return ans;
    }
};