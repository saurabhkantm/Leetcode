class Solution {
public:
    int n, m;
    int totValidBlocks;

    int solve(int i, int j, int blocks, int ei, int ej, vector<vector<int>> &grid, vector<vector<int>> &vis) {
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == -1) return 0;
        if(i == ei && j == ej && blocks == totValidBlocks) return 1;
        if(i == ei && j == ej) return 0; // required if we reach the end early (blocks != totValidBlocks)

        vis[i][j] = 1;

        int up = solve(i-1, j, blocks+1, ei, ej, grid, vis);
        int down = solve(i+1, j, blocks+1, ei, ej, grid, vis);
        int left = solve(i, j-1, blocks+1, ei, ej, grid, vis);
        int right = solve(i, j+1, blocks+1, ei, ej, grid, vis);

        vis[i][j] = 0; // backtrack

        return (up + down + left + right);
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<int> start(2), end(2);
        totValidBlocks = 2;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) start = {i, j};
                else if(grid[i][j] == 2) end = {i, j};
                else if(grid[i][j] == 0) totValidBlocks++;
            }
        }

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = solve(start[0], start[1], 1, end[0], end[1], grid, vis);
        return ans;
    }
};