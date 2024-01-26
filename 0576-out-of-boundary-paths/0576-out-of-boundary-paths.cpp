class Solution {
public:
    int mod = 1e9+7;

    int memo(int row, int col, int moveCount, int maxMove, int m, int n, vector<vector<vector<int>>>& dp){
        if(row < 0 || row >= m || col < 0 || col >= n){
            if(moveCount <= maxMove) return 1;
            else return 0;
        }

        if(moveCount > maxMove) return 0;

        if(dp[row][col][moveCount] != -1) return dp[row][col][moveCount];

        int dirX[4] = {0, 1, 0, -1};
        int dirY[4] = {1, 0, -1, 0};

        int ans = 0;

        for(int i = 0; i < 4; i++){
            int nextRow = row + dirX[i];
            int nextCol = col + dirY[i];

            ans = (ans%mod) + (memo(nextRow, nextCol, moveCount+1, maxMove, m, n, dp)%mod);
        }

        dp[row][col][moveCount] = ans%mod;
        return dp[row][col][moveCount];
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        return memo(startRow, startColumn, 0, maxMove, m, n, dp);
    }
};