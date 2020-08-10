class Solution {
    vector<int> edges[100001];
    int inDeg[100001];
    public:
    vector<int> kahn(int n){
        priority_queue<int, vector<int>, greater<int> > q;
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(inDeg[i] == 0){
                q.push(i);
                v.push_back(i);
            }
        }

        while(!q.empty()){
            while(!q.empty()){
                int front = q.top();
                q.pop();
                for(auto child : edges[front]){
                    inDeg[child]--;
                    if(inDeg[child] == 0){
                        q.push(child);
                        v.push_back(child);
                    }
                }
            }
        }
        if(v.size() == n)
            return v;
        else{
            vector<int> v;
            return v;
        }
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        
        if(n == 1){
            vector<int> v;
            v.push_back(0);
            return v;
        }
        
        for(int i = 0; i < m; i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            edges[b].push_back(a);
            inDeg[a]++;
        }
        
        vector<int> ans = kahn(n);
        return ans;
    }
};