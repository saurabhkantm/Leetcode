class Solution {
public:
    int n;
    vector<vector<int>> direction{{1,0},{-1,0},{0,1},{0,-1}};

    bool solve(vector<vector<int>>& dist, int mid) {
        if (dist[0][0] < mid) return false;

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        q.push({0, 0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i == n - 1 && j == n - 1)
                return true;

            for (auto &dir : direction) {
                int ni = i + dir[0];
                int nj = j + dir[1];

                if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                    !vis[ni][nj] && dist[ni][nj] >= mid) {

                    vis[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, -1));
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        queue<pair<int,int>> q;

        // Multi-source BFS from all thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        int level = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [i, j] = q.front();
                q.pop();

                dist[i][j] = level;

                for (auto &dir : direction) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];

                    if (ni < 0 || ni >= n || nj < 0 || nj >= n || vis[ni][nj])
                        continue;

                    vis[ni][nj] = true;
                    q.push({ni, nj});
                }
            }

            level++;
        }

        int l = 0;
        int r = min(dist[0][0], dist[n - 1][n - 1]);
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (solve(dist, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};