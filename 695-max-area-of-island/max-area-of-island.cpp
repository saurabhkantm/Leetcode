class Solution {
public:
    int m, n;

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {

        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0;

        if (visited[i][j] || grid[i][j] == 0)
            return 0;

        visited[i][j] = true;

        return 1 +
               dfs(grid, visited, i + 1, j) +
               dfs(grid, visited, i - 1, j) +
               dfs(grid, visited, i, j + 1) +
               dfs(grid, visited, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int maxi = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (!visited[i][j] && grid[i][j] == 1) {
                    int area = dfs(grid, visited, i, j);
                    maxi = max(maxi, area);
                }
            }
        }

        return maxi;
    }
};