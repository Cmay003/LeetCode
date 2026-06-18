class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x=(hour%12)*30;
        double div=(double)minutes/5;
        double y=((div))*30;
        double z=minutes*0.5;
        double ans=abs(x-y);
        if(x>=y) ans+=z;
        else if(x<y) ans-=z;
        return ans;
    }
};