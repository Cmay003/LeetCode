class Solution {
public:
    int value(char c){
        if(c=='I'){
            return 1;
        }
        else if(c=='V'){
            return 5;
        }
        else if(c=='X'){
            return 10;
        }
        else if(c=='L'){
            return 50;
        }
        else if(c=='C'){
            return 100;
        }
        else if(c=='D'){
            return 500;
        }
        else if(c=='M'){
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int total=0;
        if(s.length()<15 || s.length()>=1){
            for(int i=0; i<s.length(); i++){
                if(value(s[i])<value(s[i+1]) && i+1<s.length()){
                    total=total-value(s[i]);
                }
                else{
                    total=total+value(s[i]);
                }
            }
            return total;
        }
        else return 0;
    }
};