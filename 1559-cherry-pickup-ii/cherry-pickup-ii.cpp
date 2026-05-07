class Solution {
public:
    int solve(int i, int j1, int j2, int n, int m, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid)
    {
        //boundary check
        if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e9;

        //memoization check
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        //base case
        if(i == n-1)
        {
            //case 1
            if(j1 == j2) return grid[i][j1];
            else return (grid[i][j1] + grid[i][j2]);
        }

        int maxi = -1e9;

        //calculate the curr value
        int curr = (j1 == j2)? grid[i][j1] : (grid[i][j1] + grid[i][j2]);

        for(int dj1= -1; dj1<=1; dj1++)
        {
            for(int dj2 = -1; dj2<=1; dj2++)
            {
                int val = curr + solve(i+1, j1 + dj1, j2 + dj2, n, m, dp, grid);
                maxi = max(val, maxi);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        //initalize 3d dp
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(0, 0, m-1, n, m, dp, grid);
        
    }
};