class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        
        for(int i = row - 1; i >= 0; i--){
            for(int j = col - 1; j >= 0; j--){
                if(i == row - 1 && j == col - 1){
                    dungeon[i][j] = max(1, 1 - dungeon[i][j]);
                } else if(i == row - 1){
                    dungeon[i][j] = max(1, dungeon[i][j + 1] - dungeon[i][j]);
                } else if(j == col - 1){
                    dungeon[i][j] = max(1, dungeon[i + 1][j] - dungeon[i][j]);
                } else {
                    dungeon[i][j] = max(1, min(dungeon[i + 1][j], dungeon[i][j + 1]) - dungeon[i][j]);
                }
            }
        }
        return dungeon[0][0];
    }
};