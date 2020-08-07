class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0){
            return (int)tasks.size();
        }
        
        map<char, int> mp;
        int mx = 0;
        for(auto e : tasks){
            mp[e]++;
            mx = max(mx, mp[e]);
        }
        
        int ans = (mx - 1) * (n + 1);
        for(auto e : mp){
            if(e.second == mx){
                ans++;
            }
        }
        
        ans = max(ans, (int)tasks.size());
        return ans;
    }
};