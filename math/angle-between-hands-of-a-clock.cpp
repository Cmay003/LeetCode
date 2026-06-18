class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x=(hour%12)*30;
        double y=((minutes/5)%12)*30;
        double z=minutes*0.5;
        double ans=(x==y)?z:abs(x-y)-z;
        return ans;
    }
};