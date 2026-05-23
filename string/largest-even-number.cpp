class Solution {
public:
    string largestEven(string s) {
        int n=s.size();
        int i=n-1;
        while(i>0){
            if(s[i]=='1'){
                s.erase(i, 1);
                i--;
            }
            else{
                break;
            }
        }
        return (s=="1")?"" :s;
    }
};