class Solution {
public:
    double angleClock(int h, int m) {
        double hourAngle = (h % 12) * 30.0 + m * 0.5;
        double minuteAngle = m * 6.0;

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);
    }
};