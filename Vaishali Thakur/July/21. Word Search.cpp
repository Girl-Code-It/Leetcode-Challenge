class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int w, int n, int m){
        if(w == word.size())
            return true;
        
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[w]){
            return false;
        }
        
        char c = board[i][j];
        board[i][j] = '#';
        bool top = dfs(board, word, i - 1, j, w + 1, n, m);
        bool right = dfs(board, word, i, j + 1, w + 1, n, m);
        bool bottom = dfs(board, word, i + 1, j, w + 1, n, m);
        bool left = dfs(board, word, i, j - 1, w + 1, n, m);        
        
        board[i][j] = c;
        return (top || right || bottom || left);
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    bool flag = dfs(board, word, i, j, 0, n, m);
                    if(flag)
                        return true;
                }
            }
        }
        return false;
    }
};