class Solution {
    int ans;
public:
    Solution(){
        ans = 0;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(i < 0 || i == n || j < 0 || j == m || grid[i][j] == 0){
            ans++;
            return;
        }
        
        if(grid[i][j] == 2){
            return;
        }
        
        grid[i][j] = 2;
        
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i, j - 1, n, m);
        dfs(grid, i, j + 1, n, m);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(n == 0) 
            return 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, n, m);
                }
            }
        }
        return ans;
    }
};