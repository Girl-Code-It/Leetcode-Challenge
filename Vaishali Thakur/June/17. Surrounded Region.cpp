class Solution {
public:
    void dfs(vector<vector<char>>& board,int r,int c,int rsize,int csize){
        if(r < 0 || c < 0 || r == rsize || c == csize || board[r][c] != 'O')
            return;
        
        board[r][c] = 'P';
        dfs(board, r + 1, c, rsize, csize);
        dfs(board, r, c + 1, rsize, csize);
        dfs(board, r - 1, c, rsize, csize);
        dfs(board, r, c - 1, rsize, csize);
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        
        int row = board.size(), col = board[0].size();
        
        for(int i = 0; i < col; i++){
            dfs(board, 0, i, row, col);
            dfs(board, row - 1, i, row, col);
        }
        
        for(int i = 0; i < row; i++){
            dfs(board, i, 0, row, col);
            dfs(board, i, col - 1, row, col);
        }
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'P')
                    board[i][j] = 'O';
            }
        }
    }
};