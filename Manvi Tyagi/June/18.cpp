class Solution {
public:
    int hIndex(vector<int>& A) {
        int n = A.size();
        if(!n) return 0;
        int st = 0, end = n-1;
        while(st <= end)
        {
            int mid = st + (end-st)/2;
            int val = A[mid];
            if(val >= n-mid)
                end = mid-1;
            else
                st = mid+1;
        }
        return n - end - 1;
    }
};