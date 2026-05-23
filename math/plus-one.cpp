class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=0;
        for(int i=n-1; i>=0; i--){
            digits[i]+=1;
            if(digits[i]==10){
                digits[i]=0;
                carry=1;
            }
            else{
                carry=0;
                break;
            }
        }
        if(carry){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};