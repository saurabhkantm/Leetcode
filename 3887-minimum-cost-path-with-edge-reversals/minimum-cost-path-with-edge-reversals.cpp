class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> list(n);

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            list[u].push_back({v, w});
            list[v].push_back({u, 2*w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        pq.push({0, 0}); // {dist, node}

        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: list[node]) {
                int v = it.first;
                int w = it.second;

                if(dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        if(dist[n-1] == 1e9) return -1;
        return dist[n-1];
    }
};