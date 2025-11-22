class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<int> dist(n+1, 1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k]=0;
        pq.push({0,k});

        vector<pair<int,int>> adj[n+1];

        for(auto a: times)
        {
            adj[a[0]].push_back({a[1], a[2]});
        }

        while(!pq.empty())
        {
            int val = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto a: adj[node])
            {
                int adjval = a.first;
                int weight = a.second;

                if(weight + val <dist[adjval])
                {
                    dist[adjval] = weight + val;
                    pq.push({dist[adjval], adjval});
                }
            }
        }

        int maxi = *max_element(dist.begin()+1,dist.end());
        
        if(maxi == 1e9) return -1;
        return maxi;


        
    }
};