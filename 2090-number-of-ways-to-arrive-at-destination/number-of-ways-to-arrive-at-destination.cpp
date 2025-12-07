class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(n);

        for(auto it: roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n,1e18);
        vector<int> ways(n,0);

        priority_queue< pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long,int>>> que;

        dist[0]=0;
        ways[0]=1;

        que.push({0, 0});
        int mod = (int) (1e9+7);
        
        while(!que.empty())
        {
            long long cost = que.top().first;
            int node = que.top().second;
            que.pop();

            for(auto a: adj[node])
            {
                long long  weight = a.second;
                int adjnode = a.first;

                long long newdist = weight + cost;

                //case1
                if(newdist < dist[adjnode])
                {
                    dist[adjnode] = weight + cost;
                    que.push({weight+cost, adjnode});
                    ways[adjnode] = ways[node];
                }

                //case2
                else if(newdist == dist[adjnode])
                {
                    ways[adjnode]= (ways[adjnode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
        
    }
};