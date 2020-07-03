class Solution {
    map<string, priority_queue<string, vector<string>, greater<string>>> v;
    vector<string> ans;
public:
    void dfs(string node){
        auto& edges = v[node];
        while(!edges.empty()){
            string child = edges.top();
            edges.pop();
            dfs(child);
        }
        ans.push_back(node);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        for(int i = 0; i < n; i++){
            string a = tickets[i][0];
            string b = tickets[i][1];
            v[a].push(b);
        }
        
        dfs("JFK");
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};