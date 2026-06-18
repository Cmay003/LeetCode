class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x=(hour%12)*30+minutes*0.5;
        double y=(((double)minutes/5))*30;
        double ans=abs(x-y);
        return min(ans,360-ans);
    }
};