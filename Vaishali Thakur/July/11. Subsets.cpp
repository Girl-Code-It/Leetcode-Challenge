class Solution {
public:
    vector<int> helper(vector<int>& a, int n){
        vector<int> v;
        int i = 0;
        while(n > 0){
            if(n & 1) 
                v.push_back(a[i]);
            i++;
            n = n >> 1;
        }
        return v;
    }
    
    vector<vector<int>> subsets(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> ans;
        int r = (1 << n) - 1;
        for(int i = 0; i <= r; i++){
            vector<int> v = helper(a, i);
            ans.push_back(v);
        }
        return ans;
    }
};