class Solution {
public:
    void sortColors(vector<int>& a) {
        int n = a.size();
        int z = 0, t = n - 1, i = 0;
        while(i <= t){
            if(a[i] == 0){
                int x = a[i];
                a[i++] = a[z];
                a[z++] = x;
            } else if(a[i] == 2){
                int x = a[i];
                a[i] = a[t];
                a[t--] = x;
            } else {
                i++;
            }
        }
    }
};