class Solution {
public:
    double myPow(double x, int n) {
        int y = abs(n);
        double p = 1;
        while(y > 0){
            if(y & 1)
                p = p * x;
            y = y >> 1;
            x = x * x;
        }
        
        if(n < 0) return 1 / p;
        else return p;
    }
};