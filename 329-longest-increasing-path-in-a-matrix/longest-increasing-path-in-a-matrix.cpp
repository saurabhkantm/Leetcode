class Solution {
public:
    int n,m;
    int dfs(int r,int c,int prev, vector<vector<int>>&dp,vector<vector<int>>& matrix){
        if(r<0 || r>=n || c<0 || c>=m)return 0;
         if (matrix[r][c] <= prev)
            return 0;
        if(dp[r][c]!=-1)return dp[r][c];
        int res=1;
        res=max(res,1+dfs(r+1,c,matrix[r][c],dp,matrix));
        res=max(res,1+dfs(r-1,c,matrix[r][c],dp,matrix));
        res=max(res,1+dfs(r,c+1,matrix[r][c],dp,matrix));
        res=max(res,1+dfs(r,c-1,matrix[r][c],dp,matrix));
        dp[r][c]=res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(i,j,-1,dp,matrix);
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;   
    }
};