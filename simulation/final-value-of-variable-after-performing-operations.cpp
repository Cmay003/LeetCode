class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto word: operations){
            if(word=="++X"){
                ++x;
            }
            else if(word=="X++"){
                x++;
            }
            else if(word=="--X"){
                --x;
            }
            else if(word=="X--"){
                x--;
            }
        }
        return x;
    }
};