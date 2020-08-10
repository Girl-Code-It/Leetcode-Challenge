class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        v.push_back(1);
        
        int i2 = 0, i3 = 0, i5 = 0;
        for(int i = 1; i < n; i++){
            int two = v[i2] * 2, three = v[i3] * 3, five = v[i5] * 5;
            int m = min(two, min(three, five));
            v.push_back(m);
            if(m == two){
                i2++;
            } 
            if(m == three){
                i3++;
            }
            if(m == five){
                i5++;
            }   
        }
        
        return v[n - 1];
    }
};