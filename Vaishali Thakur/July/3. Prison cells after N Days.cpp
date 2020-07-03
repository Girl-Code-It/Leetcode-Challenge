class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& res, int n) {
        vector<int> v(8);
        vector<vector<int>> prisonState;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= 6; j++){
                if(res[j - 1] == res[j + 1]) 
                    v[j] = 1;
                else 
                    v[j] = 0;
            }
            if(prisonState.size() && prisonState.front() == v) 
                return prisonState[(n - i - 1) % prisonState.size()]; 
            else 
                prisonState.push_back(v);
            res = v;
        }
        return res;
    }
};