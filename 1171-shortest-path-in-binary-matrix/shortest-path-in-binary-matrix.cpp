class Solution {
public:
    int dx[8]= {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8]= {-1, 0, 1, 1, -1, -1, 0, 1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        if(n==1 && grid[n-1][n-1]) return -1;
        if(n==1 && !grid[n-1][n-1]) return 1;

        dist[0][0]=1; //source;

        //queue
        queue<pair<int, pair<int, int>>> que;
        que.push({1, {0, 0}});

        //edge case
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        while(!que.empty())
        {
            int distance = que.front().first;
            int x = que.front().second.first;
            int y = que.front().second.second;
            que.pop();

            for(int i=0; i<8; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0 && (distance + 1 < dist[nx][ny]))
                {   
                    if(nx == n-1 && ny == n-1) return (distance +1);

                    dist[nx][ny]=distance+1;
                    que.push({distance+1, {nx, ny}});
                }
            }
        }
        return -1;
    }
};