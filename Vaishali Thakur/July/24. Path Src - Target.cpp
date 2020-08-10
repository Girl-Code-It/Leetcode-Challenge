class Solution {
    vector<vector<int>> ans;
    vector<int> v;
public:
    void dfs(vector<vector<int>>& graph, int source, int target){
        if(source == target) 
            ans.push_back(v);
        for(auto child: graph[source]) {
			v.push_back(child);
			dfs(graph, child, target);
			v.pop_back();
		}
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size() - 1;
        v.push_back(0);
        dfs(graph, 0, n);
        return ans;
    }
};