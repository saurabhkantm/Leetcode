class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0, 1, 0, -1};

    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n= heights.size();
        int m= heights[0].size();

        priority_queue<
        pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> pq;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        pq.push({0,{0,0}});
        dist[0][0]=0;

        while(!pq.empty())
        {
            int distance = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == m-1) return distance;

            for(int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m)
                {
                    int newEffort = max(abs(heights[x][y]-heights[nx][ny]), distance);

                    if(newEffort < dist[nx][ny])
                    {
                        dist[nx][ny]= newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }
        return 0;
    }
};