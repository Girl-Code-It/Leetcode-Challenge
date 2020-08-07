class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12) 
            hour = 0;  
        if(minutes == 60){ 
            minutes = 0; 
            hour += (hour <= 12) ? 1 : -11;
         }  

        double hourAngle = (hour * 30) + (minutes) / 2.0;  
        double minAngle = 6 * minutes;  

        double angle = abs(hourAngle - minAngle);  

        angle = (angle > 180) ? (360.0 - angle) : angle;  

        return angle; 
    }
};