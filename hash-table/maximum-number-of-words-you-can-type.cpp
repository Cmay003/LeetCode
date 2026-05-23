class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool map[26]={false};
        for(char ch:brokenLetters){
            map[ch-'a']=true;
        }
        bool canType=true;
        int result=0;
        for(char ch:text){
            if(ch==' '){
                if(canType){
                    result++;
                }
                canType=true;
            }
            else if(map[ch-'a']==true){
                canType=false;
            } 
        }
        if(canType) result++;
        return result;
    }
};