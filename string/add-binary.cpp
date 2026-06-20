class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int n=a.size(), m=b.size();
        int size1=n-1;
        int size2=m-1;
        int carry=0;
        while(size1>=0 || size2>=0 || carry==1){
            int sum=carry;
            if(size1>=0) sum+=a[size1--]-'0';
            if(size2>=0) sum+=b[size2--]-'0';
            ans+=(sum%2)+'0';
            carry=sum/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};