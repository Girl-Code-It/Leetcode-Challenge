class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for(int i = 0; i < n; i++){
            int j = i + 1, k = n - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if(nums[i] + nums[j] + nums[k] < 0){
                    j++;
                } else {
                    k--;
                }
            }
        }
        vector<vector<int>> v (s.begin(), s.end());
        return v;
    }
};