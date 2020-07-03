class Solution {
public:
    int hIndex(vector<int>& v) {
        int n = v.size(), s = 0, e = n;
        while(s < e){
            int m = s + (e - s) / 2;
            if(v[m] < (n - m))
                s = m + 1;
            else
                e = m;
        }
        return n - s;
    }
};