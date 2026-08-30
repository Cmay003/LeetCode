class Solution {
public:
    vector<int> numOfBurgers(int tomato, int cheese) {
        if(cheese>tomato) return {};
        if(tomato%2!=0) return {};
        int jumbo=0, small=0;
        while(cheese>0){
            if(cheese*4>tomato){
                tomato-=2;
                cheese--;
                small++;
            }
            else{
                tomato-=4;
                cheese--;
                jumbo++;
            }
        }
        if(tomato==0 && cheese==0) return {jumbo,small};
        return {};
    }
};