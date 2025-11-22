class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int,int>>adj[n];

        for(auto a: flights)
        {
            adj[a[0]].push_back({a[1],a[2]});
        }

        vector<int> dist(n, 1e9);

        dist[src]=0;
        queue<pair<int, pair<int, int>>> que;
        que.push({0, {src,0}});

        while(!que.empty())
        {
            int stops=que.front().first;
            int node = que.front().second.first;
            int cost = que.front().second.second;
            que.pop();

            if(stops>k) continue;

            for(auto ad: adj[node])
            {
                int adjval = ad.first;
                int weight = ad.second;

                if(cost + weight < dist[adjval])
                {
                    dist[adjval]= cost+weight;
                    que.push({stops+1, {adjval, dist[adjval]}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};