class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
        int m = grid.size();
        int n = grid[0].size();
        if(i==m-1 && j==n-1){
            return grid[m-1][n-1];
        }
        if(i<0 || i>=m || j<0 || j>=n){
            return INT_MAX/2;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int dirRow[2] = {1,0};
        int dirCol[2] = {0,1};
        int ans = INT_MAX;
        for(int idx=0;idx<2;idx++){
            int take = grid[i][j] + solve(grid,i+dirRow[idx],j+dirCol[idx],dp);
            ans = min(ans,take);
        }
        return dp[i][j] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        int ans = solve(grid,0,0,dp);
        return ans;
    }
};