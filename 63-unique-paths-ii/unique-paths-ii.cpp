class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n));
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        dp[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                }
                else{
                    int take1 = 0;
                    int take2 = 0;
                    if(i-1>=0){
                        take1 = dp[i-1][j];
                    }
                    if(j-1>=0){
                        take2 = dp[i][j-1];
                    }
                    dp[i][j] = take1 + take2;
                }
            }
        }
        return dp[m-1][n-1];
    }
};