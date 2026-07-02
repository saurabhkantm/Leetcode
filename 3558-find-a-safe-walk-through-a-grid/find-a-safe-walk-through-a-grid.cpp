class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        dist[0][0] = grid[0][0];
        dq.push_front({0, 0});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while (!dq.empty()) {
            auto [x, y] = dq.front(); dq.pop_front();
            if(x == m - 1 && y == n - 1) return true;
            for(int d = 0; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                int cost = dist[x][y] + grid[nx][ny];
                if(cost >= health) continue;
                if(dist[x][y] + grid[nx][ny] < dist[nx][ny]){
                    dist[nx][ny] = dist[x][y] + grid[nx][ny];
                    if(grid[nx][ny] == 0)  dq.push_front({nx, ny});
                    else dq.push_back({nx, ny});
                }
            }
        }
        return false;
    }
};