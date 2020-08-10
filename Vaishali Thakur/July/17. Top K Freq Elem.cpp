class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for(auto e : m){
            pq.push({e.second, e.first});
        }
        
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};