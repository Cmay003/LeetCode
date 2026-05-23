class Solution {
public:
    int secondHighest(string s) {
        int largest = -1;
        int second = -1;
        for(int i=0; i<s.size(); i++){
            if('0'<=s[i] && s[i]<='9'){
                int num = s[i]-'0';
                if(num>largest){
                    second = largest; 
                    largest = num;
                }
                if(num<largest && num>second){
                    second = num;
                } 
            }
        }
        return second;
    }
};